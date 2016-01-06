package com.gluedtomatoes.artrix;
import android.app.Activity;
import android.content.Context;
import android.graphics.Point;
import android.support.v7.internal.view.menu.ActionMenuItemView;
import android.view.Display;

/**
 * Created by gsarwal on 5/8/2015.
 */
public class Constants {
    public static float deltaTime = 0.0f;
    public static Camera camera = (Camera) SceneManager.createCamera("Default Camera", new Vector4(0, 0, 1.0f), new Vector4(0, 0f, 0), Dimension.mAspectRatio, 0.5f, 1000);
    //public static Camera camera = (Camera) SceneManager.createCamera("Default Camera", new Vector4(0,0,0), new Vector4(0, 0, 1), 60.0f, Dimension.mAspectRatio, 0.5f, 1000.0f);
}
