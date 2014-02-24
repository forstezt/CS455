#version 130

uniform float velocityX = 0.0;
uniform float velocityY = 0.0;
uniform float beta = 0.0;

in vec2 position;
in vec3 color;

out vec3 fcolor;

void main() {

	float tempX = position.x * cos(beta) - position.y * sin(beta);
	float tempY = position.x * sin(beta) + position.y * cos(beta);

	float newX = 0.5f * (tempX) + velocityX;
	float newY = 0.5f * (tempY) + velocityY;
	
	gl_Position = vec4(newX, newY, 0.0, 1.0);
	fcolor = color;
}