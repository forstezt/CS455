#version 130

uniform sampler2DShadow shadow_map;
uniform vec3 albedo;
uniform vec3 light_position_eye;
uniform vec3 spot_direction_eye;

in vec3 fposition_eye;
in vec3 fnormal_eye;
in vec4 ftexcoord;

void main() {
    vec3 light_direction_eye = normalize(light_position_eye - fposition_eye);
    vec3 normal_eye = normalize(fnormal_eye);

    float d_dot_l = dot(-spot_direction_eye, light_direction_eye);
    float spottedness = max(pow(d_dot_l, 4.0), 0.3);

    float n_dot_l = max(dot(light_direction_eye, normal_eye), 0.0);

    float shadowedness = textureProj(shadow_map, ftexcoord);
    gl_FragColor = vec4(albedo * n_dot_l * spottedness * shadowedness, 1.0);
}
