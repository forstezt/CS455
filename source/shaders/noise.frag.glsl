#version 130

uniform sampler2D tex;

in vec2 ftexcoord;

void main() {

	//generates clouds
	float noise = texture(tex, ftexcoord).r;
	gl_FragColor = mix(vec4(0.0, 0.0, 1.0, 1.0), vec4(1.0), noise);
}