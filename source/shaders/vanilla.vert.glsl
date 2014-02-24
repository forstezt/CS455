#version 130

uniform mat4 xform;
uniform mat4 xform2;
in vec3 position;

void main() {
	gl_Position = xform2 * xform * vec4(position, 1.0);
}