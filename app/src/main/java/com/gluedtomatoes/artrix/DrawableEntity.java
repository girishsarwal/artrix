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

    protected ShaderProgram mShadingProgram;

    protected VertexDescriptor mVertexDescriptor;

    protected Transform mTransform;

    DrawableEntity(){
        buffers = new int[2];
        mVisible = true;
        mTransform = new Transform();
    }
    public DrawableEntity(Node node, String shader){
        this.node = node;
        setShadingProgram(shader);
    }
    public DrawableEntity(String shader){
        setShadingProgram(shader);
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
    public void update(double gameTime) {

        if(!mIsInitialized){
            init();
        }
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
