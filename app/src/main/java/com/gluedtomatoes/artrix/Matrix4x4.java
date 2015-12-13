package com.gluedtomatoes.artrix;

import android.opengl.Matrix;

/**
 * Created by gsarwal on 10/26/2015.
 */
public class Matrix4x4 {
    private float
            _11, _12, _13, _14,
            _21, _22, _23, _24,
            _31, _32, _33, _34,
            _41, _42, _43, _44;

    private float[] _mat;
    public float[] getMat(){
        return _mat;
    }

    public  Matrix4x4(){
        _11 = _22 = _33 = _44 = 1.0f;
        _mat = new float[16];
        Matrix.setIdentityM(_mat, 0);
    }

    public Matrix4x4 identity(){
        Matrix.setIdentityM(_mat, 0);
        return this;
    }

    public Matrix4x4 multiply(Matrix4x4 rhs){
        Matrix4x4 n = new Matrix4x4();
        Matrix.multiplyMM(n._mat, 0, _mat, 0, rhs._mat, 0);
        return n;
    }

    public Matrix4x4 set(float _11, float _12, float _13, float _14,
                         float _21, float _22, float _23, float _24,
                         float _31, float _32, float _33, float _34,
                         float _41, float _42, float _43, float _44){
        _mat[0] = _11; _mat[1] = _12; _mat[2] = _13; _mat[3] = _14;
        _mat[4] = _21; _mat[5] = _22; _mat[6] = _23; _mat[7] = _24;
        _mat[8] = _31; _mat[9] = _32; _mat[10] = _33; _mat[11] = _34;
        _mat[12] = _41; _mat[13] = _42; _mat[14] = _43; _mat[15] = _44;
        return this;
    }
    public Matrix4x4 setElement(int row, int column, float elementValue){
        _mat[((row - 1) * 4) + column] = elementValue;
        return this;
    }

    public Matrix4x4 setRow(int row, float _1, float _2, float _3, float _4){
        _mat[((row - 1) * 4) + 0] = _1;
        _mat[((row - 1) * 4) + 1] = _2;
        _mat[((row - 1) * 4) + 2] = _3;
        _mat[((row - 1) * 4) + 3] = _4;
        return this;
    }

}
