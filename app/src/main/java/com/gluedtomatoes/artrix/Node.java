package com.gluedtomatoes.artrix;

/**
 * Created by girishsarwal on 16/12/15.
 */
public interface Node {
    public String getName();

    public void setName(String name);

    public Node createChild(String name);

    public Node getChild(String name);

    public void removeAllChildren();

    public void removeChild(String name);

    public Vector4 getInitialPosition();

    public Vector4 getInitialScale();

    public void translate(Vector4 vector);

    public void scale(Vector4 vector);

    public void rotate(Vector4 axis, float angle);

    public void pitch(float angle);

    public void roll(float angle);

    public void yaw(float angle);

    public Node getParent();

}