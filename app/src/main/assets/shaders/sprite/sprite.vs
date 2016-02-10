attribute vec4 inPosition;
attribute vec2 inTex0;
uniform mat4 theMVP;

varying vec2 texCoord;
void main() {
   gl_Position = theMVP * inPosition;
   texCoord = inTex0;
}