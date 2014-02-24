
#Create class used to randomize landscape
class Terrandom
	def initialize(*args)
		@rng = Random.new
		@max = args[0]
		@decayFactor = args[1]
	end
	
	def rand
		return @rng.rand(2.0 * @max) - @max
	end
	
	def decay
		@max *= @decayFactor
	end
end



#size is 2^n + 1
size = ARGV[0].to_i
grid = Array.new(size) {Array.new(size) {0.0}}
random = Terrandom.new(ARGV[1].to_f, ARGV[2].to_f)

#Priming step, puts values in four corners
grid[0][0] = random.rand
grid[0][size - 1] = random.rand
grid[size - 1][0] = random.rand
grid[size - 1][size - 1] = random.rand
random.decay


radius = size / 2
while radius >= 1 do
	diameter = 2 * radius
	
	#X step
	for y in (radius...size).step(diameter) do
		for x in (radius...size).step(diameter) do
			grid[y][x] = (grid[y - radius][x - radius] +
						  grid[y - radius][x + radius] + 
						  grid[y + radius][x - radius] +
						  grid[y + radius][x + radius]) / 4.0 + random.rand
		end
	end
			
	
	#+ step
	for y in (radius...size).step(diameter) do
		for x in (0...size).step(diameter) do
			nbors = 0
			for bor in [
				[x - radius, y], # West
				[x + radius, y], # East
				[x, y - radius], # South
				[x, y + radius] # North
			] do
				# does neighbor exist?
				# har vecino?
				# if so, add it up
				if bor[0] >= 0 && bor[0] < size && bor[1] >= 0 && bor[1] < size
					grid[y][x] += grid[bor[1]][bor[0]]
					grid[x][y] += grid[bor[0]][bor[1]] # by flipping x and y, we hit the rest of the points
					nbors += 1
				end
			end
			
			# average that sum
			grid[y][x] = grid[y][x] / nbors + random.rand
			grid[x][y] = grid[x][y] / nbors + random.rand
		end
	end
	
	radius /= 2
	random.decay
end


#for r in 0...size do
#	for c in 0...size do
#		printf("%7.2f ", grid[r][c])
#	end
#	puts
#end

puts "#{size * size} #{(size - 1) * (size - 1) * 2}"

for r in 0...size do
	for c in 0...size do
		puts "v #{c} #{r} #{grid[r][c]}"
	end
end

for r in 0...size - 1 do
	for c in 0...size - 1 do
		bl = r * size + c + 1
		br = bl + 1
		tr = br + size
		tl = bl + size
		puts "f #{bl} #{br} #{tr}"
		puts "f #{bl} #{tr} #{tl}"
	end
end