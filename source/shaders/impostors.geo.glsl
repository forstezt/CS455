#version 150

layout(points) in;
layout(triangle_strip) out;
layout(max_vertices=4) out;

uniform mat4 projection;
uniform mat4 xform;

out vec2 ftexcoord;

void main() {
    float size = 0.1;
    vec4 right_eye = vec4(size, 0.0, 0.0, 0.0);
    vec4 up_eye = vec4(0.0, size, 0.0, 0.0);

    vec4 position_eye = xform * gl_in[0].gl_Position;

    gl_Position = projection * (position_eye - right_eye - up_eye);
    ftexcoord = vec2(0.0, 0.0);
    EmitVertex();

    gl_Position = projection * (position_eye + right_eye - up_eye);
    ftexcoord = vec2(1.0, 0.0);
    EmitVertex();

    gl_Position = projection * (position_eye - right_eye + up_eye);
    ftexcoord = vec2(0.0, 1.0);
    EmitVertex();
    
    gl_Position = projection * (position_eye + right_eye + up_eye);
    ftexcoord = vec2(1.0, 1.0);
    EmitVertex();
    
    EndPrimitive();
}
