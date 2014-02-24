#version 130

uniform vec3 albedo;
uniform vec3 light_position;

in vec3 fnormal;
in vec3 fposition;

void main() {
	vec3 light_direction = normalize(light_position - fposition);
	vec3 normal = normalize(fnormal);
	float litness = max(0.0, dot(light_direction, normal));

	vec3 diffuse = albedo * litness * 0.8;
	vec3 ambient = albedo * 0.2;
	
	vec3 rgb = ambient + diffuse;
	
	gl_FragColor = vec4(rgb, 1.0);
}