#version 330
in vec4 vertex_color;			/** input color from vs **/
in vec2 vertex_tex_coord;		/** input tex coord from vs **/
uniform vec4 gradColor;		/** the texture sampler **/
out vec4 outColor;				/** final color of fragment **/
void main()
{
   //outColor = texture2D(texture, vertex_tex_coord);
   float lerpValue = gl_FragCoord.y/400.0;
   outColor = mix(vec4(1.0, 1.0, 1.0, 1.0), gradColor, lerpValue);
};
