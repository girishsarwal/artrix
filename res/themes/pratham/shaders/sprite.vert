#version 120
attribute vec3 in_position;
attribute vec4 in_color;
attribute vec2 in_uv;
attribute vec3 in_normal;

varying vec4 vertex_color;
varying vec2 vertex_texel;
varying vec3 vertex_normal;

void main()
{
	vertex_color = in_color;
	vertex_texel = in_uv;
	vertex_normal = in_normal;
	gl_Position = vec4(in_position.x, in_position.y, in_position.z, 1.0) + vertex_normal;	/** so normal does not get optimized out **/
}
