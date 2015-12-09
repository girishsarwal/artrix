attribute vec2 inPosition;
attribute vec2 inTex0;

varying vec2 texCoord;
void main() {
   gl_Position = vec4(inPosition.xy, 0.2, 1.0);
   texCoord = inTex0;
}