#version 120
attribute in vec3 position;
attribute in vec4 color;
attribute in vec2 tex0;

varying vec4 vertex_color;			/** passed onto fs **/
varying vec2 vertex_tex_coord;		/** passed onto fs **/
uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;

void main()
{
	vertex_color = color;
	vertex_tex_coord = tex0;
	
	gl_Position = vec4(position, 1.0);
}
