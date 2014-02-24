#version 130

uniform samplerCube fog_box;

in vec3 ftexcoords;

void main() {

	gl_FragColor = texture(fog_box, ftexcoords).rrrr;
	gl_FragColor.a *= 0.2;
	
}