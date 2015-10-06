varying vec2 v_texture;

uniform sampler2D gSampler;

void main()
{
    gl_FragColor = texture2D( gSampler, v_texture.xy );
}