package com.gluedtomatoes.artrix;

import android.opengl.GLES20;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/**
 * Created by gsarwal on 5/8/2015.
 */
public class Sprite extends DrawableEntity  {

    public Sprite(String texture){
        mTexture = TextureManager.use(texture);
    }

    private static float vertices[]={
            -1.0f, 1.0f, 0.0f, 0.0f,
            -1.0f, -1.0f, 0.0f, 1.0f,
            1.0f, -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 0.0f,
    };

    private static short indices[] = {
            0, 1, 2,
            0, 2, 3,
    };

    private Texture mTexture;

    @Override
    public void init() {
        mVertexDescriptor = PredefinedVertexDescriptors.VF_SPRITE;
        setShadingProgram("sprite");

        ByteBuffer bbv = ByteBuffer.allocateDirect(vertices.length * VertexDescriptor.SIZE_OF_FLOAT);

        bbv.order(ByteOrder.nativeOrder());
        vertexBuffer = bbv.asFloatBuffer();
        vertexBuffer.put(vertices);
        vertexBuffer.position(0);

        ByteBuffer bbi = ByteBuffer.allocateDirect(indices.length * VertexDescriptor.SIZE_OF_SHORT);

        bbi.order(ByteOrder.nativeOrder());
        indexBuffer = bbi.asShortBuffer();
        indexBuffer.put(indices);
        indexBuffer.position(0);


        mVertexCount = vertexBuffer.remaining();
        mIndexCount = indexBuffer.remaining();
        mTriangleCount = mIndexCount/3;


        GLES20.glGenBuffers(2, buffers, 0);

        GLES20.glBindBuffer(GLES20.GL_ARRAY_BUFFER, buffers[0]);
        GLES20.glBufferData(GLES20.GL_ARRAY_BUFFER, mVertexCount * VertexDescriptor.SIZE_OF_FLOAT, vertexBuffer, GLES20.GL_STATIC_DRAW);

        GLES20.glBindBuffer(GLES20.GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
        GLES20.glBufferData(GLES20.GL_ELEMENT_ARRAY_BUFFER, mIndexCount * VertexDescriptor.SIZE_OF_SHORT, indexBuffer, GLES20.GL_STATIC_DRAW );

        super.init();
    }

    @Override
    public void render() {
        mTexture.use();
        mShadingProgram.use();
        mShadingProgram.setUniformInteger("theTexture", 0);
        mShadingProgram.setUniformInteger("theMVP", 0);
        mShadingProgram.applyVertexAttribute(mVertexDescriptor);
        GLES20.glDrawElements(GLES20.GL_TRIANGLES, mIndexCount, GLES20.GL_UNSIGNED_SHORT, 0);
        super.render();
        mShadingProgram.disableVertexAttributes();
    }
}
