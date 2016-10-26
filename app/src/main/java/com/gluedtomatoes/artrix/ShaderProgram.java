package com.gluedtomatoes.artrix;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLES20;
import android.util.Log;

import java.io.IOException;
import java.util.HashMap;

/**
 * Created by gsarwal on 9/14/2015.
 */
public class ShaderProgram {

    public static String SHADERS_ROOT = "shaders";
    private static HashMap<String, ShaderProgram> mShaderPrograms = new HashMap<>();

    private Integer mNativeId;
    private String mName;

    private HashMap<String, Integer> mUniformsMap;
    private HashMap<String, Integer> mAttributesMap;

    public ShaderProgram(String name){
        mName = name;
        mUniformsMap = new HashMap<>();
        mAttributesMap = new HashMap<>();
    }

    private void setNativeId(int nativeId){
        mNativeId = nativeId;
    }

    public void use(){
        GLES20.glUseProgram(mNativeId);
    }


    public void setUniformVector(String uniform, Vector4 vector){
        Integer uniformLocation = mUniformsMap.get(uniform);
        if (uniformLocation != null) {
            GLES20.glUniformMatrix4fv(uniformLocation, 1, false, vector.getRaw(), 0);
        }
    }

    public void setUniformMatrix(String uniform, Matrix4x4 matrix){
        Integer uniformLocation = mUniformsMap.get(uniform);
        if (uniformLocation != null) {
            GLES20.glUniformMatrix4fv(uniformLocation, 1, false, matrix.getRaw(), 0);
        }
    }

    public void setUniformFloat(String uniform, float value){
        Integer uniformLocation = mUniformsMap.get(uniform);
        if (uniformLocation != null) {
            GLES20.glUniform1f(uniformLocation, value);
        }
    }

    public void setUniformInteger(String uniform, Integer  value){
        Integer uniformLocation = mUniformsMap.get(uniform);
        if (uniformLocation != null) {
            GLES20.glUniform1i(uniformLocation, value);
        }
    }

    public static void init(Context context){

        AssetManager am = context.getAssets();
        String[] list;

        try {
            list = am.list(SHADERS_ROOT);
            for(String s: list) {
                mShaderPrograms.put(s, createShadingProgram(am, s));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static ShaderProgram createShadingProgram(AssetManager am, String name) {
        String vsPath = String.format("%s/%s/%s.vs", SHADERS_ROOT, name, name);
        String psPath = String.format("%s/%s/%s.ps", SHADERS_ROOT, name, name);
        String vsSource = AssetLoader.readAssetString(am, vsPath);
        String psSource = AssetLoader.readAssetString(am, psPath);
        ShaderProgram program = new ShaderProgram(name);

        program.setNativeId(compileProgram(
                loadShader(GLES20.GL_VERTEX_SHADER, vsSource),
                loadShader(GLES20.GL_FRAGMENT_SHADER, psSource)
        ));

        program.fetchAttributes();
        program.fetchUniforms();
        return program;
    }

    private static int loadShader(int shaderType, String resource){
        int shader = GLES20.glCreateShader(shaderType);
        if (shader != 0) {
            GLES20.glShaderSource(shader, resource);
            GLES20.glCompileShader(shader);
            int[] compiled = new int[1];
            GLES20.glGetShaderiv(shader, GLES20.GL_COMPILE_STATUS, compiled, 0);
            if (compiled[0] == 0) {
                Log.e("Shader Load Error", "Could not compile shader " + shaderType + ":" + resource);
                Log.e("Shader Load Error", GLES20.glGetShaderInfoLog(shader));
                GLES20.glDeleteShader(shader);
                shader = 0;
                return shader;
            }
        }
        Log.i("SHADER_COMPILER", "Shader " + resource + "Compiled successfully!");
        return shader;
    }

    public static int compileProgram (int vertexShader, int fragmentShader) {
        int program = GLES20.glCreateProgram();
        if (program != 0) {
            GLES20.glAttachShader(program, vertexShader);
            GLES20.glAttachShader(program, fragmentShader);
            GLES20.glLinkProgram(program);
            int[] linkStatus = new int[1];
            GLES20.glGetProgramiv(program, GLES20.GL_LINK_STATUS, linkStatus, 0);
            if (linkStatus[0] != GLES20.GL_TRUE) {
                Log.e("Shader Error", "Could not link program: ");
                Log.e("Shader Error", GLES20.glGetProgramInfoLog(program));
                GLES20.glDeleteProgram(program);
                program = 0;
                return program;
            }
        }
        Log.i("PROGRAM_COMPILER", "Shader Program Linked successfully!");
        return program;
    }

    private void fetchUniforms() {
        fetchUniform("theTexture");
        fetchUniform("theMVP");
        fetchUniform("theGameTime");
    }

    private void fetchAttributes() {
        fetchAttribute("inPosition");
        fetchAttribute("inColor");
        fetchAttribute("inTex0");
        fetchAttribute("inTex1");
        fetchAttribute("inTex2");
        fetchAttribute("inTex3");
        fetchAttribute("inNormal");
        fetchAttribute("inTangent");
    }


    private void fetchUniform(String uniformName){
        int hUniform = getUniformLocation(uniformName);
        if(hUniform >= 0){
            mUniformsMap.put(uniformName, hUniform);
        }
    }

    private void fetchAttribute(String elementName){
        use();
        int hAttribute = getAttributeLocation(elementName);
        if(hAttribute >= 0){
            mAttributesMap.put(elementName, hAttribute);
        }
    }

    public int getAttributeLocation(String elementName){
        return GLES20.glGetAttribLocation(mNativeId, elementName);
    }

    public int getUniformLocation(String elementName){
        return GLES20.glGetUniformLocation(mNativeId, elementName);
    }

    public void applyVertexAttribute(VertexDescriptor descriptor){
        use();
        for(String key: mAttributesMap.keySet()){
            GLES20.glEnableVertexAttribArray(mAttributesMap.get(key));
            VertexAttribute vattr = descriptor.getVertexAttribute(key);
            GLES20.glVertexAttribPointer(getAttributeLocation(key), vattr.mElementSize, vattr.mType, vattr.mNormalized, descriptor.getStride(), vattr.mOffsetInStream);
        }
    }

    public void disableVertexAttributes(){
        use();
        for(int value: mAttributesMap.values()){
            GLES20.glDisableVertexAttribArray(value);
        }
    }

    public VertexDescriptor createSuitableVertexFormat(){
        int format = 0;
        VertexDescriptor vertexDescriptor = new VertexDescriptor(0);
        if(mAttributesMap.containsKey("inPosition")){
            format |= vertexDescriptor.POSITION;
            
        }
        if(mAttributesMap.containsKey("inColor")){
            format |= vertexDescriptor.COLOR_RGB;
        }
        if(mAttributesMap.containsKey("inTex0")){
            format |= vertexDescriptor.TEX0;
        }
        vertexDescriptor.setFormat(format);
        return vertexDescriptor;
    }

    public  static ShaderProgram get(String name){
        return mShaderPrograms.get(name);
    }

}
