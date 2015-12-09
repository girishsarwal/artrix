package com.gluedtomatoes.artrix;

import android.content.Context;
import android.content.res.AssetManager;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by girishsarwal on 9/12/15.
 */
public class AssetLoader {
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
    public static String readAssetString(AssetManager am, String name){
        String string = "";
        try {

            byte[] buffer = new byte[1024];
            ByteArrayOutputStream baos = new ByteArrayOutputStream();

            InputStream in = am.open(name);
            int read = 0;
            while ((read = in.read(buffer)) != -1) {
                baos.write(buffer, 0, read);
            }
            string = baos.toString();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return string;
    }

}
