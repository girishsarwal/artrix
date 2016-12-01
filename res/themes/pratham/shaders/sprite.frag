#version 120
varying vec4 vertex_color;
varying vec2 vertex_texel;
varying vec3 vertex_normal;

uniform sampler2D texture;

void main()
{
   gl_FragColor = vertex_color * texture2D(texture, vertex_texel);
}
