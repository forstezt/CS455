#version 130

/*
 * Shader with orthographic projection, applied transformation,
 * point light and cel shading
 */

uniform mat4 projection;
uniform mat4 xform;

in vec3 position;
in vec3 normal;

out vec3 fposition;
out vec3 fnormal;

void main() {
  // Set the position
  vec4 transformed_position = xform * vec4(position, 1.0);
  gl_Position = projection * transformed_position;
  
  fnormal = (xform * vec4(normal, 0.0)).xyz;
  fposition = transformed_position.xyz;
}