#version 130

uniform vec3 albedo;
uniform vec3 light_position;

in vec3 fnormal;
in vec3 fposition;

void main() {
	vec3 light_direction = normalize(light_position - fposition);
	vec3 normal = normalize(fnormal);
	
	//Diffuse
	float litness = max(0.0, dot(light_direction, normal));
	vec3 diffuse = albedo * litness * 0.9;
	
	//Ambient
	vec3 ambient = albedo * 0.1;
	
	//Specular
	float shininess = 50.0;
	/*vec3 reflection = -light_direction + 2.0 * dot(normal, light_direction) * normal;*/
	vec3 eye = normalize(vec3(0.0) - fposition);
	vec3 halfway = normalize(eye + light_direction);
	vec3 specular_color = vec3(1.0);
	/*vec3 specular = specular_color * pow(max(0.0, dot(reflection, eye)), shininess);*/
	vec3 specular = specular_color * pow(max(0.0, dot(halfway, normal)), shininess);
	
	vec3 rgb = diffuse + ambient + specular;
	
	gl_FragColor = vec4(rgb, 1.0);
}