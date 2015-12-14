package com.gluedtomatoes.artrix;

import android.graphics.Point;
import android.opengl.GLES20;

import java.nio.FloatBuffer;
import java.nio.ShortBuffer;

/**
 * Created by gsarwal on 5/18/2015.
 */
public class DrawableEntity extends Entity implements Renderable{
    protected FloatBuffer vertexBuffer;
    protected ShortBuffer indexBuffer;

    protected int[] buffers;

    protected int mVertexCount = 0;
    protected int mTriangleCount = 0;
    protected int mIndexCount = 0;

    protected boolean mVisible;
    protected Vector4 mPosition;
    protected Vector4 mSize;
    protected float mRotation;

    protected ShaderProgram mShadingProgram;

    protected VertexDescriptor mVertexDescriptor;

    protected Transform mTransform;

    DrawableEntity(){
        buffers = new int[2];
        mPosition = new Vector4();
        mRotation = 0.0f;
        mSize = new Vector4();
        mVisible = true;
        mTransform = new Transform();
    }
    public DrawableEntity(String shader){
        setShadingProgram(shader);
    }


    public float getRotation() {
        return mRotation;
    }
    public void setRotation(float mRotation) {
        this.mRotation = mRotation;
    }

    public Vector4 getPosition() {
        return mPosition;
    }
    public void setPosition(Vector4 mPosition) {
        this.mPosition = mPosition;
    }
    public void setPosition(Point mPosition) {
        setPosition(Dimension.PixelsToCoords(mPosition));
    }


    public Vector4 getSize() {
        return mSize;
    }
    public void setSize(Vector4 mSize) {
        this.mSize = mSize;
    }
    public void setSize(Point mSize) {
        setSize(Dimension.PixelsToCoords(mSize));
    }

    public ShaderProgram getShadingProgram(){
        return mShadingProgram;
    }
    public void setShadingProgram(String shadingProgram){
        mShadingProgram = ShaderProgram.get(shadingProgram);
    }

    public VertexDescriptor getVertexDescriptor(){
        return mVertexDescriptor;
    }
    public void setVertexDescriptor(VertexDescriptor vertexFormat) {
        mVertexDescriptor = vertexFormat;
    }


    @Override
    public void init()
    {
        mIsInitialized = true;
    }

    @Override
    public void setVisible(Boolean visible) {
        mVisible = visible;
    }

    @Override
    public Boolean getVisible() {
        return null;
    }

    @Override
    public void update() {

        if(!mIsInitialized){
            init();
        }
        mTransform.update();
        /* is this visible this frame, if yes push it **/
        if(mVisible){
            ArtrixView.RenderQueue.Enque(this);
        } else {
            ArtrixView.RenderQueue.Remove(this);
        }
    }

    @Override
    public void render() {

    }
}
