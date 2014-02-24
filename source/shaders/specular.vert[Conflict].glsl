#version 130

uniform mat4 projection;
uniform mat4 xform;

in vec3 position;
in vec3 normal;

out vec3 fnormal;
out vec3 fposition;

void main() {
  vec4 transformed_position = xform * vec4(position, 1.0);
	
  gl_Position = projection * transformed_position;
  
  fnormal = (xform * vec4(normal, 0.0)).xyz;
  fposition = transformed_position.xyz;
  
}