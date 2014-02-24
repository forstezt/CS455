#version 130

const vec3 albedo = vec3(1.0, 0.0, 0.0);
uniform vec3 light_position;

in vec3 fnormal;
in vec3 fposition;

void main() {
	vec3 light_direction = normalize(light_position - fposition);
	vec3 normal = normalize(fnormal);
	float litness = max(0.0, dot(light_direction, normal));
	
	litness = ceil(3 * litness) * 0.25;

	gl_FragColor = vec4(albedo * litness, 1.0f);
}