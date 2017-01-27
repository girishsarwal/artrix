#version 120
varying vec2 vertex_texel;

uniform sampler2D texture0;

void main()
{
   gl_FragColor = texture2D(texture0, vertex_texel);
}
