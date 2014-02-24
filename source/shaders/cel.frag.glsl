#version 130

/*
 * Shader with orthographic projection, applied transformation,
 * point light and cel shading
 */

uniform vec4 light_position = vec4(0.0, 0.0, 0.0, 0.0);
 
const vec3 albedo = vec3(1.0, 0.0, 0.0);

// Take in litness calculation variables
in vec3 fnormal;
in vec3 fposition;

void main() {
	// Calculate the shading
	vec3 light_direction = normalize(5*light_position.xyz - fposition);
	float litness = max(0.0, dot(light_direction, normalize(fnormal)));

	gl_FragColor = vec4(albedo * litness, 1.0f);

}