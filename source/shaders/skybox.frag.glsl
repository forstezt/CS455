#version 130

uniform samplerCube image;

in vec3 ftexcoords;

void main() {

	gl_FragColor = texture(image, ftexcoords);
	
}