package com.gluedtomatoes.artrix;

import android.content.Context;
import android.content.res.AssetManager;
import android.opengl.GLES20;

import java.io.IOException;
import java.util.HashMap;

/**
 * Created by girishsarwal on 8/12/15.
 */
public class TextureManager {
    public static String TEXTURES_ROOT = "textures";
    private static HashMap<String, Texture> mTextureMap= new HashMap<>();

    public static void init(Context context){
        AssetManager am = context.getAssets();
        String[] list;

        try {
            list = am.list(TEXTURES_ROOT);
            for(String s: list) {
                Texture texture = Texture.loadFromAssets(am, String.format("%s/%s", TEXTURES_ROOT, s));
                if(texture != null) {
                    mTextureMap.put(s, texture);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static Texture use(String textureName){
        return mTextureMap.get(textureName).use();
    };
}
