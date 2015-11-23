attribute vec3 position;
attribute vec4 color;

varying vec4 vColor;

uniform mat4 model_to_world;
uniform mat4 world_to_eye;
uniform mat4 eye_to_clip;

void main(void)
{
    gl_Position = eye_to_clip * world_to_eye * model_to_world * vec4(position, 1.0);
    vColor = color;
}