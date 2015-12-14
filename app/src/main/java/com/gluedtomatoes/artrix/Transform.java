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
        mMvp.identity();
        if(mParent != null){
            mWorld = mParent.getWorld().multiplyAndClone(mLocal);
        } else mWorld = mLocal;

        if (mCamera != null) {
            mMvp.multiply(mCamera.getView());
            mMvp.multiply(mWorld);
        }
    }

    public Matrix4x4 getLocal(){
        return mLocal;
    }
    public Matrix4x4 getWorld(){
        return mWorld;
    }

    public Matrix4x4 getMVP(Camera camera){
        return mMvp;
    }
    public Matrix4x4 getBillboardMVP(Camera camera){
        Matrix4x4 bbMatrix = mMvp.clone();
        bbMatrix.clearUpperTriangle();
        return  bbMatrix;
    }
    public Transform translate(float x, float y, float z){
        Matrix.translateM(mLocal.getRaw(), 0, x, y, z);
        return this;
    }
    public Transform rotateZ(float angle){
        Matrix.rotateM(mLocal.getRaw(),0, angle, 0, 0, 1);
        return this;
    }
}
