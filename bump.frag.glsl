#version 130

uniform sampler2D tex;
uniform vec3 light_position_eye = vec3(0.0, 0.0, 0.0);
uniform vec3 albedo = vec3(0.05f);

in vec2 ftexcoord;
in vec3 fposition_eye;

void main() {
	//const int reach = 1;
	//float here = texture(tex, ftexcoord).r;
	//float right = textureOffset(tex, ftexcoord, ivec2(reach, 0));
	//float up = textureOffset(tex, ftexcoord, ivec2(0, reach));
	
	//float scale = 1.0;
	//vec3 tangentRight = vec3(scale, 0.0, right - here);
	//vec3 tangentUp = vec3(0.0, scale, right - here);
	
	//vec3 normal_eye = normalize(cross(tagentRight, tagentUp));

	vec3 normal_eye = texture(tex, ftexcoord).rgb * 2.0 - 1.0;
	
	normal_eye.z *= 3.5; 
	normal_eye = normalize(normal_eye);
	
	//Diffuse
	vec3 light_direction = normalize(light_position_eye - fposition);
	float n_dot_l = max(0.0, dot(light_direction, normal_eye));
	
	//Specular
	vec3 eye_direction = (vec3(0.0) - fposition_eye);
	vec3 halfway = normalize(eye_direction + light_direction);
	float specularity = pow(max(dot(halfway, normal), 0.0), 90.0);
	
	vec3 rgb = albedo * n_dot_l + vec3(1.0) * specularity;
	
	gl_FragColor = vec4(rgb, 1.0);
}