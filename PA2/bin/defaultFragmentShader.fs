varying vec3 color;

void main(void)
{
    gl_FragColor = vec4(color.rgb, 5.0);
}