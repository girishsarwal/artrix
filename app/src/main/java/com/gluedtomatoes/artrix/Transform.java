package com.gluedtomatoes.artrix;

import android.opengl.Matrix;

/**
 * Created by gsarwal on 5/8/2015.
 */
public class Transform {
    public static Matrix4x4 getMVP(SceneNode node, Camera camera){
        Matrix4x4 m = new Matrix4x4();
        Matrix4x4 w = node.getWorld().clone();
        Matrix4x4 v = camera.getView().clone();
        Matrix4x4 p = camera.getProjection().clone();

        m.multiply(p);
        m.multiply(v);
        m.multiply(w);



        Matrix4x4 mvp = m.multiplyAndClone(w.multiplyAndClone(v).multiplyAndClone(p));
        return m;
    }
    public static Matrix4x4 getBillboardMVP(SceneNode node, Camera camera){
        return null;
    }
}
