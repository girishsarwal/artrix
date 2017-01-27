#version 330
layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 tex0;

varying vec4 vertex_color;			/** passed onto fs **/
varying vec2 vertex_tex_coord;		/** passed onto fs **/

void main()
{
	vertex_color = color;
	vertex_tex_coord = tex0;
	
	gl_Position = vec4(position, 1.0);
}
