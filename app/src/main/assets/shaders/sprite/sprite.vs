attribute vec2 inPosition;
attribute vec2 inTex0;
uniform mat4 theMVP;

varying vec2 texCoord;
void main() {

   mat4 transform = theProjection * theView * theWorld;
   gl_Position = vec4(inPosition.xy, 0.2, 1.0);
   texCoord = inTex0;
}