attribute vec4 inPosition;
attribute vec4 inColor;
uniform mat4 theMVP;
uniform float theGameTime;

 varying vec4 vColor;

 void main() {
    gl_Position = inPosition;
    vColor = inColor;
 }