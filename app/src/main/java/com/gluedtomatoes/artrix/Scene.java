package com.gluedtomatoes.artrix;

import java.util.HashMap;

/**
 * Created by gsarwal on 12/18/2015.
 */
public class Scene {
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    String name;
    private Scene(String name){
        this.name = name;
        root = new SceneNode("__root__", null);
    }
    public SceneNode getRoot() {
        return root;
    }

    public void setRoot(SceneNode root) {
        this.root = root;
    }



    private SceneNode root;

    public void setAmbientLight(){

    }
    public Entity createMeshEntity(){
        return new DrawableEntity();
    };

    public static Scene create(String name){
        return new Scene(name);
    }

    public void update(double gameTime){
        root.update(gameTime);
    }
}
