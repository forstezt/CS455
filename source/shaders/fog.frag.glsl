#version 130

uniform sampler3D fog_plane;

in vec3 ftexcoord;

void main() {
	vec4 fog_color = texture(fog_plane, ftexcoord).rrrr;
	fog_color.r = mix(fog_color.r, 184.0 / 255.0, 0.6); 
	fog_color.g = mix(fog_color.g, 134.0 / 255.0, 0.6); 
	fog_color.b = mix(fog_color.b, 11.0 / 255.0, 0.6);
	gl_FragColor = vec4(fog_color);
	gl_FragColor.a *= 0.2;
}