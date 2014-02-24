#version 130

uniform mat4 projection;
uniform mat4 xform;

in vec3 position;

void main() {
    gl_Position = projection * xform * vec4(position, 1.0);
}
