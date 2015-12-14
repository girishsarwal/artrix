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
    public static Camera camera = new Camera(new Vector4(), new Vector4(1, 0, 1), Dimension.mScreenWidthPixels/Dimension.mScreenHeightPixels, 60.0f, 1.0f, 1000.0f);
}
