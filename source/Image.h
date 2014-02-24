#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image {
	public:
		Image(const std::string& path, bool is_flipped);
		Image(const std::string& path);
		Image(int width, int height, int nchannels);
		int GetWidth() const;
		int GetHeight() const;
		const unsigned char* GetPixels() const;
		int GetChannelCount() const;

		void WriteToFile(const std::string& path);
		
		unsigned char* operator()(int c, int r);
		//unsigned char operator()(int c, int r, int channel);
		unsigned char& operator()(int c, int r, int channel);
		const unsigned char& operator()(int c, int r, int channel) const;

		float operator()(float c, float r, int channel);	
		static Image* GetWhiteNoise(int width, int height, int nchannels);
		static Image* GetSmoothNoise(int width, int height, int noctaves);
		Image* Scale(int new_width, int new_height);
		
	private:
		int width;
		int height;
		int nchannels;
		unsigned char* pixels;
};

#endif