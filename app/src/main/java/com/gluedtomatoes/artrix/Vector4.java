package com.gluedtomatoes.artrix;

import android.opengl.Matrix;

/**
 * Created by girishsarwal on 9/12/15.
 */

public class Vector4 {
    public float[] _raw;

    public Vector4(float mX, float mY, float mZ, float mW) {
        _raw = new float[4];
        _raw[0] = mX; _raw[1] = mY; _raw[2] = mZ; _raw[3] = mW;
    }

    public Vector4(float mX, float mY, float mZ) {
        _raw = new float[4];
        _raw[0] = mX; _raw[1] = mY; _raw[2] = mZ; _raw[3] = 1.0f;
    }

    public Vector4() {
        _raw = new float[4];
        _raw[0] = 0.0f; _raw[1] = 0.0f; _raw[2] = 0.0f; _raw[3] = 1.0f;
    }
    public float getX(){
        return _raw[0];
    }
    public float getY(){
        return _raw[1];
    }
    public float getZ(){
        return _raw[2];
    }
    public float getW(){
        return _raw[3];
    }

    public float[] getRaw(){
        return _raw;
    }

    public void zero(){
        _raw[0] = _raw[1] = _raw[2] = 0; _raw[3] = 1;
    }
    public Vector4 set(float x, float y, float z, float w){
        _raw[0] = x; _raw[1] = y; _raw[2] = z; _raw[3] = w;
        return this;
    }
    public Vector4 set(float x, float y, float z){
        _raw[0] = x; _raw[1] = y; _raw[2] = z;
        return this;
    }
    public double magnitude(){
        return Math.sqrt(magnitudeSq());
    }
    public double magnitudeSq(){
        return (_raw[0] * _raw[0] +
                        _raw[1] * _raw[1] +
                        _raw[2] * _raw[2] +
                        _raw[3] * _raw[3]);
    }

    public void multiply(Matrix4x4 mat){
        float[] rawMatrix = mat.getRaw();
        _raw[0] = _raw[0] * rawMatrix[0] + _raw[1] * rawMatrix[4] + _raw[2] * rawMatrix[8] + _raw[3] * rawMatrix[12];
        _raw[1] = _raw[0] * rawMatrix[1] + _raw[1] * rawMatrix[5] + _raw[2] * rawMatrix[9] + _raw[3] * rawMatrix[13];
        _raw[2] = _raw[0] * rawMatrix[2] + _raw[1] * rawMatrix[6] + _raw[2] * rawMatrix[10] + _raw[3] * rawMatrix[14];
        _raw[3] = _raw[0] * rawMatrix[3] + _raw[1] * rawMatrix[7] + _raw[2] * rawMatrix[11] + _raw[3] * rawMatrix[15];
    };

    public void multiply(Vector4 rhs){
        _raw[0] *= rhs._raw[0];
        _raw[1] *= rhs._raw[1];
        _raw[2] *= rhs._raw[2];
    }

    public void add(Vector4 rhs){
        _raw[0] += rhs._raw[0];
        _raw[1] += rhs._raw[1];
        _raw[2] += rhs._raw[2];
    }


}

