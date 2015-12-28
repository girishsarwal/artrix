attribute vec3 inPosition;
attribute vec2 inTex0;
uniform mat4 theMVP;

varying vec2 texCoord;
void main() {
   gl_Position = theMVP * vec4(inPosition.xy, 0.1, 1.0);
   texCoord = inTex0;
}