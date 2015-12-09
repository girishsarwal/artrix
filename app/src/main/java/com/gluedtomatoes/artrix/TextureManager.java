package com.gluedtomatoes.artrix;

import android.content.Context;
import android.content.res.AssetManager;

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
                int texid = 0;  /** TODO: do this with a GenTexture **/
                Texture texture = new Texture(texid);
                texture.loadFromAssets(am, s);
                if(texture != null) {
                    mTextureMap.put(s, texture);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void use(String textureName){

    };
}
