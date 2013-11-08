#version 120
attribute in vec3 position;
attribute in vec4 color;

varying vec4 vertex_color;			/** passed onto fs **/

void main()
{
	vertex_color = color;
	gl_Position = vec4(position, 1.0);
}
