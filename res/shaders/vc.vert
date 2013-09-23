#version 120
in vec4 position;
in vec4 multMatrix;
void main()
{
   gl_Position = position * multMatrix;
}
