package com.gluedtomatoes.artrix;

/**
 * Created by girishsarwal on 9/12/15.
 */
public class Vector4 {
    public float mX;
    public float mY;
    public float mZ;
    public float mW;

    public Vector4(float mX, float mY, float mZ, float mW) {
        this.mX = mX;
        this.mY = mY;
        this.mZ = mZ;
        this.mW = mW;
    }

    public Vector4(float mX, float mY, float mZ) {
        this();
        this.mX = mX;
        this.mY = mY;
        this.mZ = mZ;
    }

    public Vector4() {
        this.mX = this.mY = this.mZ = 0.0f;
        this.mW = 1.0f;
    }

}
