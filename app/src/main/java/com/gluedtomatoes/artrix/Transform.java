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
        Matrix.setIdentityM(mWorld, 0);

    }

    private Transform mParent;
    protected float[] mLocal = new float[16];
    protected float[] mWorld = new float[16];

    public void update(){
        if(mParent == null){
            mWorld = mLocal;
            return;
        }
        Matrix.multiplyMM(mWorld, 0, mParent.mWorld, 0, mLocal, 0);
    }



}
