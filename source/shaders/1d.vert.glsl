#version 130

uniform mat4 xform;
uniform mat4 ortho;

in vec3 position;
in vec3 normal;

out vec3 fposition_eye;
out vec3 fnormal_eye;

void main() {

  	vec4 position_eye = xform * vec4(position, 1.0);
	gl_Position = ortho * position_eye;
	
	fposition_eye = position_eye.xyz;
	fnormal_eye = (xform * vec4(normal, 0.0)).xyz;
  
}