#version 120
in vec4 position;
varying vec2 texel;
void main()
{
   //Transform the vertex
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
   
   //Pass the texture coordinate ahead to the fs
   texel = vec2(gl_MultiTexCoord0);
}
