#version 120
in vec4 position;
void main()
{
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}