package com.gluedtomatoes.artrix;

import android.opengl.Matrix;

/**
 * Created by gsarwal on 5/8/2015.
 */
public class Transform {
    public Transform(){
        mParent = null;
        mLocal = new Matrix4x4();
        mWorld = new Matrix4x4();
        mMvp = new Matrix4x4();
        mCamera = null;
    }

    private Transform mParent;
    protected Matrix4x4 mLocal;
    protected Matrix4x4 mWorld;
    protected Matrix4x4 mMvp;

    public void setmCamera(Camera mCamera) {
        this.mCamera = mCamera;
    }

    protected Camera mCamera;

    public void update() {
        mWorld.identity();
        mMvp.identity();

        if (mParent == null) {
            mWorld = mLocal;
        } else mWorld.multiply(mLocal);


    }

    public Matrix4x4 getLocal(){
        return mLocal;
    }
    public Matrix4x4 getWorld(){
        return mWorld;
    }

    public Matrix4x4 getMVP(Camera camera){
        if(mCamera != null){
            mMvp.multiply(mCamera.getView());
            mMvp.multiply(mWorld);
        }
        return mMvp;
    }

    public Transform translate(float x, float y, float z){
        Matrix.translateM(mLocal.getRaw(), 0, x, y, z);
        return this;
    }
}
