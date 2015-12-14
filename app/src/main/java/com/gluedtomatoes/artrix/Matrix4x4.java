package com.gluedtomatoes.artrix;

import android.opengl.Matrix;

/**
 * Created by gsarwal on 10/26/2015.
 */
public class Matrix4x4 {
    private float[] _raw;
    public float[] getRaw(){
        return _raw;
    }

    public  Matrix4x4(){
        _raw = new float[16];
        Matrix.setIdentityM(_raw, 0);
    }

    public Matrix4x4 identity(){
        Matrix.setIdentityM(_raw, 0);
        return this;
    }

    public Matrix4x4 multiplyAndClone(Matrix4x4 rhs){
        Matrix4x4 n = new Matrix4x4();
        Matrix.multiplyMM(n._raw, 0, _raw, 0, rhs._raw, 0);
        return n;
    }
    public void multiply(Matrix4x4 rhs){
        Matrix.multiplyMM(_raw, 0, _raw, 0, rhs._raw, 0);
    }

    public Matrix4x4 set(float _11, float _12, float _13, float _14,
                         float _21, float _22, float _23, float _24,
                         float _31, float _32, float _33, float _34,
                         float _41, float _42, float _43, float _44){
        _raw[0] = _11; _raw[1] = _12; _raw[2] = _13; _raw[3] = _14;
        _raw[4] = _21; _raw[5] = _22; _raw[6] = _23; _raw[7] = _24;
        _raw[8] = _31; _raw[9] = _32; _raw[10] = _33; _raw[11] = _34;
        _raw[12] = _41; _raw[13] = _42; _raw[14] = _43; _raw[15] = _44;
        return this;
    }
    public Matrix4x4 setElement(int row, int column, float elementValue){
        _raw[((row - 1) * 4) + column] = elementValue;
        return this;
    }

    public Matrix4x4 setRow(int row, float _1, float _2, float _3, float _4){
        _raw[((row - 1) * 4) + 0] = _1;
        _raw[((row - 1) * 4) + 1] = _2;
        _raw[((row - 1) * 4) + 2] = _3;
        _raw[((row - 1) * 4) + 3] = _4;
        return this;
    }

}
