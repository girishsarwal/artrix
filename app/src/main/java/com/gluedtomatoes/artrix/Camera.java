package com.gluedtomatoes.artrix;

import android.opengl.Matrix;

/**
 * Created by gsarwal on 12/14/2015.
 */
public class Camera extends Entity {
    private Vector4 mPosition;
    private Vector4 mLookAt;
    private Vector4 mUp;

    private float mAspectRatio;
    private float mNearPlane;
    private float mFarPlane;
    private float mFov;



    public Matrix4x4 getView() {
        return mView;
    }

    public Matrix4x4 getProjection() {
        return mProjection;
    }

    private Matrix4x4 mProjection;
    private Matrix4x4 mView;

    public static Camera create(String name, Vector4 position, Vector4 lookAt, float aspectRatio, float near, float far){
        return new Camera(name, position, lookAt, aspectRatio, near, far);
    }
    public static Camera create(String name, Vector4 position, Vector4 lookAt, float fov, float aspectRatio, float near, float far){
        return new Camera(name, position, lookAt, fov, aspectRatio, near, far);
    }

    private Camera(String name, Vector4 position, Vector4 lookAt, float aspectRatio, float near, float far) {
        setName(name);

        mProjection = new Matrix4x4();
        mView = new Matrix4x4();
        mUp = new Vector4(0.0f, 1.0f, 0.0f);

        mPosition = position;
        mLookAt = lookAt;
        mAspectRatio = aspectRatio;

        mNearPlane = near;
        mFarPlane = far;
    }

    private Camera(String name, Vector4 position, Vector4 lookAt, float fov, float aspectRatio, float near, float far) {
        setName(name);

        mProjection = new Matrix4x4();
        mView = new Matrix4x4();
        mUp = new Vector4(0.0f, 1.0f, 0.0f);

        mPosition = position;
        mLookAt = lookAt;
        mAspectRatio = aspectRatio;
        mFov = fov;

        mNearPlane = near;
        mFarPlane = far;
    }


    @Override
    public void update(double gameTime) {
        Matrix.setLookAtM(mView.getRaw(), 0, mPosition.getX(), mPosition.getY(), mPosition.getZ(), mLookAt.getX(), mLookAt.getY(), mLookAt.getZ(), mUp.getX(), mUp.getY(), mUp.getZ());
        Matrix.frustumM(mProjection.getRaw(), 0, -mAspectRatio, mAspectRatio, -1.0f, 1.0f, mNearPlane, mFarPlane);
        //Matrix.perspectiveM(mPosition._raw, 0, mFov, mAspectRatio, mNearPlane, mFarPlane);
    }
}
