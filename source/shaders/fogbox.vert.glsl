#version 130

uniform mat4 projection;
uniform mat4 xform;

in vec3 position;

out vec3 ftexcoords;

void main() {

  vec4 position_eye = xform * vec4(position, 1.0);
  gl_Position = projection * position_eye;
  
  ftexcoords = position;
  
}