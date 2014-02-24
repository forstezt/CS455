#version 130

uniform mat4 projection;
uniform mat4 xform;

in vec3 position;
in vec2 texcoord;

out vec2 ftexcoord;

uniform vec4 right = vec4(1.0, 0.0, 0.0, 0.0);
uniform vec4 up = vec4(0.0, 1.0, 0.0, 0.0);

void main() {
	float x_scale = 1.5;
	float y_scale = 10.0;
	vec4 position_eye = xform * vec4(position, 1.0) + right * texcoord.x * x_scale + up * texcoord.y * y_scale;
	gl_Position = projection * position_eye;

	ftexcoord = texcoord * 0.5 + 0.5;

}