#version 150

uniform sampler2D impostor;

in vec2 ftexcoord;

void main() {
    gl_FragColor = texture(impostor, ftexcoord);    
}
