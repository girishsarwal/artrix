package com.gluedtomatoes.artrix;

import android.content.res.AssetManager;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLES20;
import android.opengl.GLUtils;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by girishsarwal on 8/12/15.
 */
public class Texture {
    private int mId;
    private String mName;
    private float mWidth;
    private float mHeight;

    public void loadFromResources(Resources resources, int resourceId){
        try {
            final int[] textureHandle = new int[1];
            GLES20.glGenTextures(1, textureHandle, 0);
            final BitmapFactory.Options options = new BitmapFactory.Options();
            options.inScaled = false;   // No pre-scaling
            final Bitmap bitmap = BitmapFactory.decodeResource(resources, resourceId, options);
            GLES20.glBindTexture(GLES20.GL_TEXTURE_2D, textureHandle[0]);
            GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_MIN_FILTER, GLES20.GL_NEAREST);
            GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_MAG_FILTER, GLES20.GL_NEAREST);
            GLUtils.texImage2D(GLES20.GL_TEXTURE_2D, 0, bitmap, 0);
            setId(textureHandle[0]);
            setWidth(bitmap.getWidth());
            setHeight(bitmap.getHeight());
            bitmap.recycle();
        }
        catch(Exception ex){

        }
    }

    public void loadFromAssets(AssetManager am, String name){
        try {
            final int[] textureHandle = new int[1];
            GLES20.glGenTextures(1, textureHandle, 0);

            final BitmapFactory.Options options = new BitmapFactory.Options();
            options.inScaled = false;   // No pre-scaling

            GLES20.glBindTexture(GLES20.GL_TEXTURE_2D, textureHandle[0]);

            byte[] bytes = readAssetBytes(am, name);
            final Bitmap bitmap = BitmapFactory.decodeByteArray(bytes, 0, bytes.length, options);

            GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_MIN_FILTER, GLES20.GL_NEAREST);
            GLES20.glTexParameteri(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_MAG_FILTER, GLES20.GL_NEAREST);

            GLUtils.texImage2D(GLES20.GL_TEXTURE_2D, 0, bitmap, 0);

            setId(textureHandle[0]);
            setWidth(bitmap.getWidth());
            setHeight(bitmap.getHeight());
            bitmap.recycle();
        }
        catch(Exception ex){

        }
    }

    public byte[] readAssetBytes(AssetManager am, String name){
        try {
            byte[] buffer = new byte[1024];
            ByteArrayOutputStream baos = new ByteArrayOutputStream();

            InputStream in = am.open(name);
            int read = 0;
            while ((read = in.read(buffer)) != -1) {
                baos.write(buffer, 0, read);
            }
            return baos.toByteArray();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
    public Texture(int texId)
    {
        mId = texId;
    }

    private void setId(int id){
        mId = id;
    }
    private void setWidth(float width){
        mWidth = width;
    }
    private void setHeight(float height){
        mHeight = height;
    }
    private int getId(){
        return mId;
    }
}
