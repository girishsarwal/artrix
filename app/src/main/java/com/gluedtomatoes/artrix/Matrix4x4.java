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


    public  Matrix4x4(){
        _11 = _22 = _33 = _44 = 1.0f;
    }

    public Matrix4x4 identity(){
       set(1.0f, 0.0f, 0.0f, 0.0f,
           0.0f, 1.0f, 0.0f, 0.0f,
           0.0f, 0.0f, 1.0f, 0.0f,
           0.0f, 0.0f, 0.0f, 1.0f);
        return this;
    }

    public Matrix4x4 multiply(Matrix4x4 rhs){
        return new Matrix4x4().set(
                _11 * rhs._11 + _12 * rhs._21 + _13 * rhs._31 + _14 * rhs._41,
                _11 * rhs._12 + _12 * rhs._22 + _13 * rhs._32 + _14 * rhs._42,
                _11 * rhs._13 + _12 * rhs._23 + _13 * rhs._33 + _14 * rhs._43,
                _11 * rhs._14 + _12 * rhs._24 + _13 * rhs._34 + _14 * rhs._44,

                _21 * rhs._11 + _22 * rhs._21 + _23 * rhs._31 + _24 * rhs._41,
                _21 * rhs._12 + _22 * rhs._22 + _23 * rhs._32 + _24 * rhs._42,
                _21 * rhs._13 + _22 * rhs._23 + _23 * rhs._33 + _24 * rhs._43,
                _21 * rhs._14 + _22 * rhs._24 + _23 * rhs._34 + _24 * rhs._44,

                _31 * rhs._11 + _32 * rhs._21 + _33 * rhs._31 + _34 * rhs._41,
                _31 * rhs._12 + _32 * rhs._22 + _33 * rhs._32 + _34 * rhs._42,
                _31 * rhs._13 + _32 * rhs._23 + _33 * rhs._33 + _34 * rhs._43,
                _31 * rhs._14 + _32 * rhs._24 + _33 * rhs._34 + _34 * rhs._44,

                _41 * rhs._11 + _42 * rhs._21 + _43 * rhs._31 + _44 * rhs._41,
                _41 * rhs._12 + _42 * rhs._22 + _43 * rhs._32 + _44 * rhs._42,
                _41 * rhs._13 + _42 * rhs._23 + _43 * rhs._33 + _44 * rhs._43,
                _41 * rhs._14 + _42 * rhs._24 + _43 * rhs._34 + _44 * rhs._44);
    }

    public Matrix4x4 set(float _11, float _12, float _13, float _14,
                         float _21, float _22, float _23, float _24,
                         float _31, float _32, float _33, float _34,
                         float _41, float _42, float _43, float _44){
        this._11 = _11; this._12 = _12; this._13 = _13; this._14 = _14;
        this._21 = _21; this._22 = _22; this._23 = _23; this._24 = _24;
        this._31 = _31; this._32 = _32; this._33 = _33; this._34 = _34;
        this._41 = _41; this._42 = _42; this._43 = _43; this._44 = _44;
        return this;
    }
}
