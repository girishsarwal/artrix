package com.gluedtomatoes.artrix;

import android.opengl.Matrix;

/**
 * Created by gsarwal on 5/8/2015.
 */
public class Transform {
    public static Matrix4x4 getMVP(SceneNode node, Camera camera){
        Matrix4x4 m = new Matrix4x4();
        m.multiply(node.getWorld().multiply(camera.getView().multiply(camera.getProjection())));
        return m;
    }
    public static Matrix4x4 getBillboardMVP(SceneNode node, Camera camera){
        Matrix4x4 m = getMVP(node, camera);
        m.clearUpperTriangle();
        return null;
    }
}
