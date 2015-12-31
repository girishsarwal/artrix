package com.gluedtomatoes.artrix;

import android.opengl.GLES20;
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

    public static void applyTranslation(Matrix4x4 mat, Vector4 vec){
        Matrix.translateM(mat.getRaw(), 0, vec.getX(), vec.getY(), vec.getZ());
    }
    public static void applyScaling(Matrix4x4 mat, Vector4 vec){

    }

    public static void applyWorldTransform(Matrix4x4 world, Matrix4x4 parentWorld, Matrix4x4 local){
        world.multiply(parentWorld).multiply(local);
    }
    public static void applyModelTransform(Matrix4x4 mvp, Matrix4x4 model){
        mvp.multiply(model);
    }

    public static void applyCameraTransforms(Matrix4x4 mvp, Camera camera){
        mvp.multiply(camera.getView()).multiply(camera.getProjection());
    }
    public static void applyDefaultCameraTransforms(Matrix4x4 mvp){
        applyCameraTransforms(mvp, SceneManager.getActiveCamera());
    }

    public static void applyTranslation(Vector4 v, Vector4 rhs){
        v.add(rhs);
    }




}
