#version 330
in vec4 vertex_color;			/** input color from vs **/
in vec2 vertex_tex_coord;		/** input tex coord from vs **/
uniform sampler2D texture;		/** the texture sampler **/

out vec4 outColor;				/** final color of fragment **/
void main()
{
   //outColor = texture2D(texture, vertex_tex_coord);
   outColor = vertex_color;
};
