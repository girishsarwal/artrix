package com.gluedtomatoes.artrix;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by girishsarwal on 16/12/15.
 */
public class SceneNode implements Node {
    private String mName;

    private Vector4 mInitialPosition;
    private Vector4 mInitialScale;
    private Vector4 mInitialOrientation;

    protected Vector4 mPosition;
    protected Vector4 mScale;
    protected float mRotation;

    protected SceneNode mParent;
    protected Entity attachedEntity;

    protected Matrix4x4 mLocal;
    protected Matrix4x4 mWorld;

    protected Matrix4x4 mMvp;
    protected Matrix4x4 mBillboardMvp;

    private HashMap<String, Node> mChildren;

    @Override
    public Node getParent() {
        return mParent;
    }

    @Override
    public void setAttachedEntity(Entity entity) {
        this.attachedEntity = entity;
        entity.node = this;
    }

    @Override
    public Entity getAttachedEntity() {
        return attachedEntity;
    }

    public Matrix4x4 getWorld() {
        return mWorld;
    }

    public Matrix4x4 getParentWorld(){
        if(mParent == null){
            return new Matrix4x4();
        }
        return mParent.getWorld();
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

    public Matrix4x4 getMvp() {
        return mMvp;
    }

    public void setMvp(Matrix4x4 mMvp) {
        this.mMvp = mMvp;
    }

    public Matrix4x4 getBillboardMvp() {
        return mBillboardMvp;
    }

    public void setBillboardMvp(Matrix4x4 mBillboardMvp) {
        this.mBillboardMvp = mBillboardMvp;
    }

    public SceneNode(String name, SceneNode parent) {
        mName = name;
        mParent = parent;

        mChildren = new HashMap<>();
        mLocal = new Matrix4x4();
        mWorld = new Matrix4x4();
        mMvp = new Matrix4x4();
        mBillboardMvp = new Matrix4x4();
        mPosition = new Vector4();
        mRotation = 0.0f;
        mScale = new Vector4();
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
        SceneNode node = new SceneNode(name, this);
        mChildren.put(name, node);
        return node;
    }
    public Node createChild(String name, Entity attachedEntity) {
        SceneNode node = new SceneNode(name, this);
        node.setAttachedEntity(attachedEntity);
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
        mPosition.add(vector);
    }

    @Override
    public void scale(Vector4 vector) {
        mScale.multiply(vector);
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

    public void update(double gameTime) {
        /** update the matrices **/
        mLocal.identity();
        mWorld.identity();

        /** update local transformations **/
        Transform.applyScaling(mLocal, mScale);
        Transform.applyTranslation(mLocal, mPosition);

        /** update world by applying parent world and local transformation **/
        Transform.applyWorldTransform(mWorld, getParentWorld(), mLocal);

        mMvp.identity();
        mBillboardMvp.identity();
        /** update model by applying the model transform**/
        Transform.applyModelTransform(mMvp, mWorld);
        /** update projection by applying the default camera transforms, view and projection **/
        Transform.applyDefaultCameraTransforms(mMvp);


        /** upate the attached entity**/
        if(attachedEntity != null){
            attachedEntity.update(gameTime);
        }

        /** update the children **/
        for(Map.Entry<String, Node> entry : mChildren.entrySet()) {
            entry.getValue().update(gameTime);
        }
    }
}