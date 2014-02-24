#version 130

in vec2 position;
in vec2 texcoord;

out vec3 ftexcoord;

uniform float time;
uniform float proportion;
uniform mat4 projection;
uniform mat4 xform;

void main() {
	vec4 position_eye = xform * vec4(position, -25.0 * proportion, 1.0);
	gl_Position = projection * position_eye;
	ftexcoord = vec3(texcoord, proportion + time);
}