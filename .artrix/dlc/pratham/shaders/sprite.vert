#version 120
attribute vec3 in_position;
attribute vec2 in_uv;
uniform mat4 in_mvp;
varying vec2 vertex_texel;

void main()
{
	vertex_texel = in_uv;
	gl_Position = in_mvp * vec4(in_position.x, in_position.y, in_position.z, 1.0);
}
