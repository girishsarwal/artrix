package com.gluedtomatoes.artrix;

import android.app.Activity;
import android.graphics.Point;
import android.view.Display;

/**
 * Created by girishsarwal on 11/12/15.
 */
public class Dimension {
    public static int mScreenWidthPixels;
    public static int mScreenHeightPixels;
    public static int mHalfscreenWidthPixels;
    public static int mHalfScreenHeightPixels;
    public static float mAspectRatio;

    public static void init(Activity activity){
        /** intiialize the constants that will be used throught **/
        Display display  = activity.getWindowManager().getDefaultDisplay();
        Point size = new Point();
        display.getSize(size);

        mScreenWidthPixels = size.x;
        mScreenHeightPixels = size.y;

        mHalfscreenWidthPixels = mScreenWidthPixels / 2;
        mHalfScreenHeightPixels = mScreenHeightPixels / 2;

        if(mScreenWidthPixels > mScreenHeightPixels)
            mAspectRatio = mScreenWidthPixels/(mScreenHeightPixels * 1.0f);
        else
            mAspectRatio = mScreenHeightPixels /(mScreenWidthPixels * 1.0f);
    }

    public static void ScreenToWorld(){

    }
    public static void WorldToScreen(){

    }
    public static Point CoordsToPixels(Vector4 vector){
        Point screen = new Point();
        screen.x = (int)vector.getX() * mScreenWidthPixels;
        screen.y = (int)vector.getY() * mScreenHeightPixels;
        return screen;
    }

    /***
     * converts from pixels to cooridnates
     */
    public static Vector4 PixelsToCoords(Point point){
        return new Vector4(point.x / mScreenWidthPixels, point.y / mScreenHeightPixels, 0.0f);
    }

}
