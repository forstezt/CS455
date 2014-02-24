#version 130

uniform mat4 translater;
uniform mat4 ortho;
in vec4 position;

void main() {
  gl_Position = translater * position;
}