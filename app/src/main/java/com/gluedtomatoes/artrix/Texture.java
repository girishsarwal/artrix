package com.gluedtomatoes.artrix;

import android.content.res.AssetManager;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLES20;
import android.opengl.GLUtils;

import org.w3c.dom.Text;

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

    public static Texture loadFromResources(Resources resources, int resourceId){
        Texture tex = null;
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

            tex = new Texture(textureHandle[0])
                    .setHeight(bitmap.getWidth())
                    .setWidth(bitmap.getHeight());
            bitmap.recycle();

        }
        catch(Exception ex){
            tex = null;
        }
        return tex;
    }

    public static Texture loadFromAssets(AssetManager am, String name){
        Texture tex = null;
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

            tex = new Texture(textureHandle[0])
                    .setHeight(bitmap.getWidth())
                    .setWidth(bitmap.getHeight());
            bitmap.recycle();
        }
        catch(Exception ex){

        }
        return tex;
    }

    public static byte[] readAssetBytes(AssetManager am, String name){
        byte[] buffer = null;
        try {
            buffer = new byte[1024];
            ByteArrayOutputStream baos = new ByteArrayOutputStream();

            InputStream in = am.open(name);
            int read = 0;
            while ((read = in.read(buffer)) != -1) {
                baos.write(buffer, 0, read);
            }
            buffer = baos.toByteArray();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return buffer;
    }

    public Texture(int texId)
    {
        mId = texId;
    }

    private Texture setId(int id){
        mId = id;
        return this;
    }
    public int getId(){
        return mId;
    }

    private Texture setWidth(float width){
        mWidth = width;
        return this;
    }
    private float getWidth(){
        return mWidth;
    }
    private Texture setHeight(float height){
        mHeight = height;
        return this;
    }

    private float getHeight(){
        return mHeight;
    }
}
