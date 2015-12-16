package com.gluedtomatoes.artrix;

import android.transition.Scene;

import java.util.HashMap;

/**
 * Created by girishsarwal on 16/12/15.
 */
public class SceneNode implements Node{
    private String mName;

    private Vector4 mInitialPosition;
    private Vector4 mInitialScale;
    private Vector4 mInitialOrientation;

    protected Vector4 mPosition;
    protected Vector4 mSize;
    protected float mRotation;

    protected  SceneNode mParent;

    public Node getParent() {
        return mParent;
    }
    public void setParent(SceneNode parent){
        this.mParent = parent;
    }

    public Matrix4x4 getMvp() {
        return mMvp;
    }

    public void setMvp(Matrix4x4 mMvp) {
        this.mMvp = mMvp;
    }

    public Matrix4x4 getWorld() {
        return mWorld;
    }

    public void setWorld(Matrix4x4 mWorld) {
        this.mWorld = mWorld;
    }

    public Matrix4x4 getLocal() {
        return mLocal;
    }

    public void setLocal(Matrix4x4 mLocal) {
        this.mLocal = mLocal;
    }

    protected Matrix4x4 mLocal;
    protected Matrix4x4 mWorld;
    protected Matrix4x4 mMvp;

    public Matrix4x4 getBillboardMvp() {
        return mBillboardMvp;
    }

    public void setBillboardMvp(Matrix4x4 mBillboardMvp) {
        this.mBillboardMvp = mBillboardMvp;
    }

    protected Matrix4x4 mBillboardMvp;

    private HashMap<String, Node> mChildren;

    public SceneNode(String name){
        mName = name;
        mLocal = new Matrix4x4();
        mWorld = new Matrix4x4();
        mMvp = new Matrix4x4();
        mPosition = new Vector4();
        mRotation = 0.0f;
        mSize = new Vector4();
    }

    @Override
    public String getName() {
        return mName;
    }

    @Override
    public void setName(String name) {
        mName = name;
    }

    @Override
    public Node createChild(String name) {
        SceneNode node = new SceneNode(name);
        node.setParent(this);
        mChildren.put(name, node);
        return node;
    }

    @Override
    public Node getChild(String name) {
        return mChildren.get(name);
    }

    @Override
    public void removeAllChildren() {
        mChildren.clear();
    }

    @Override
    public void removeChild(String name) {
        mChildren.remove(name);
    }

    @Override
    public Vector4 getInitialPosition() {
        return mInitialPosition;
    }

    @Override
    public Vector4 getInitialScale() {
        return mInitialScale;
    }


    @Override
    public void translate(Vector4 vector) {

    }

    @Override
    public void scale(Vector4 vector) {

    }

    @Override
    public void rotate(Vector4 axis, float angle) {

    }

    @Override
    public void pitch(float angle) {

    }

    @Override
    public void roll(float angle) {

    }

    @Override
    public void yaw(float angle) {

    }

    public void update(){
        mMvp.identity();
        if(mParent != null){
            mWorld = mParent.getWorld().multiplyAndClone(mLocal);
        } else mWorld = mLocal;

        if (SceneManager.getActiveCamera()!= null) {
            mMvp.multiply(SceneManager.getActiveCamera().getView());
            mMvp.multiply(mWorld);
        }
    }
}
