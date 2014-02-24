#version 130

uniform mat4 projection;
uniform mat4 xform;

in vec3 position;
in vec2 texcoord;

out vec2 ftexcoord;
out vec3 fposition_eye;

void main() {
	vec4 position_eye = xform * vec4(position, 1.0);
	gl_Position = projection * position_eye;
	
	ftexcoord = texcoord;
	fposition_eye = position_eye.xyz;
}