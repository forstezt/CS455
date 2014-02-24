#version 130

uniform sampler2D impostor;
in vec2 ftexcoord;
uniform float time;

void main() {
	vec2 perturbed_texcoord;
	perturbed_texcoord.x = ftexcoord.x + (sin(time * -800.0 + (360.0 * ftexcoord.y)) + cos(time * -800.0 + (360.0 * ftexcoord.y)) * cos(time * -800.0 + (360.0 * ftexcoord.y))) * 0.01;
	perturbed_texcoord.y = ftexcoord.y;
	gl_FragColor = texture(impostor, perturbed_texcoord);

	if(gl_FragColor.a < 0.5) discard;
}