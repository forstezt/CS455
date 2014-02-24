#version 130

uniform sampler3D surface;
uniform samplerCube skybox;
uniform vec3 albedo = vec3(0.0, 0.2, 0.5);

in vec2 ftexcoord;
in vec3 incident;
in vec3 fposition_eye;

uniform float time = 0.5;


void main() {

	//Look up neighbors
	float here = texture(surface, vec3(ftexcoord / 2.0, time)).r;
	float right = textureOffset(surface, vec3(ftexcoord / 2.0, time), ivec3(2, 0, 0)).r;
	float up = textureOffset(surface, vec3(ftexcoord / 2.0, time), ivec3(0, 2, 0)).r;

	//Compute tangent vectors
	vec3 tangentRight = vec3(1.0, right - here, 0.0);
	vec3 tangentUp = vec3(0.0, up - here, 1.0);

	//Compute normal
	vec3 fnormal_world = cross(tangentRight, tangentUp);

	fnormal_world = vec3((fnormal_world + vec3(0.0, 1.0, 0.0)) / 2.0);

	//reflect vector from eye about normal
	vec3 r = reflect(incident, fnormal_world);

	//look up color in skybox
	vec3 env = texture(skybox, r).rgb;

	//color by modulated albedo
	vec3 rgb = env * albedo; 

	gl_FragColor = vec4(rgb, 1.0);

}
