package com.gluedtomatoes.artrix;

import android.app.Activity;
import android.graphics.Point;
import android.opengl.Matrix;
import android.view.Display;

/**
 * Created by gsarwal on 5/8/2015.
 */
public class Transform {
    public Transform(){
        mParent = null;
        mLocal = new Matrix4x4();
        mWorld = new Matrix4x4();
    }

    private Transform mParent;
    protected Matrix4x4 mLocal;
    protected Matrix4x4 mWorld;

    public void update(){
        if(mParent == null){
            mWorld = mLocal;
            return;
        }
        mWorld.multiply(mLocal);
    }

    public Matrix4x4 getLocal(){
        return mLocal;
    }
    public Matrix4x4 getWorld(){
        return mWorld;
    }

    public Transform translate(float x, float y, float z){
        Matrix.translateM(mLocal.getMat(), 0, x, y, z);
        return this;
    }
}
