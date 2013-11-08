#version 120
in vec4 vertex_color;
varying out vec4 outputColor;
void main()
{
   outputColor = vertex_color;
};
