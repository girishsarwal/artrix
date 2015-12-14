package com.gluedtomatoes.artrix;

/**
 * Created by gsarwal on 5/8/2015.
 */
public interface Renderable {
    public Vector4 getPosition();
    public void setPosition(Vector4 position);
    public Vector4 getSize();
    public void setSize(Vector4 size);
    public float getRotation();
    public void setRotation(float rotation);
    public void setVisible(Boolean visible);
    public Boolean getVisible();

    public void render();
}
