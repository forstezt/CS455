#version 130

const vec3 albedo = vec3(1.0, 0.0, 0.0);
in float lightness;

void main() {
	gl_FragColor = vec4(albedo * lightness, 1.0f);
}