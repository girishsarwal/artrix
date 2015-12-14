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
}

