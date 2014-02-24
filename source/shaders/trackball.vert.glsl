#version 130

uniform vec3 light_direction = vec3(1.0, 0.0, 0.0);

uniform mat4 rotater;
uniform mat4 xform;
uniform mat4 ortho;
in vec4 position;

in vec3 normal;

out float lightness;

void main() {
  //gl_Position = ortho * rotater * position;
  gl_Position = ortho * xform * position;
  lightness = max(0.0, dot(light_direction, normal));
  
}