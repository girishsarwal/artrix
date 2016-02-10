package com.gluedtomatoes.artrix;

import java.util.HashMap;

/**
 * Created by gsarwal on 6/16/2015.
 */
public class SceneManager {
    public SceneManager(){

    }
    private static HashMap<String, Camera> cameras = new HashMap<>();
    public static HashMap<String, Camera> getCameras() {
        return cameras;
    }

    private static HashMap<String, Scene> scenes  = new HashMap<>();
    public static HashMap<String, Scene> getScenes() {
        return scenes;
    }

    private static Camera activeCamera;
    public static Camera getActiveCamera() {
        return activeCamera;
    }
    public static Camera setActiveCamera(String camera) {
        activeCamera= cameras.get(camera);
        return  activeCamera;
    }

    private static Scene activeScene;
    public static Scene getActiveScene() {
        return activeScene;
    }
    public static Scene setActiveScene(String scene) {
        activeScene= scenes.get(scene);
        return activeScene;
    }




    public static Entity createCamera(String name, Vector4 position, Vector4 lookAt, float aspectRatio, float fov, float near, float far){
        Camera camera = Camera.create(name, position, lookAt, aspectRatio, fov, near, far);
        cameras.put(name, camera);
        return setActiveCamera(name);
    };

    public static Scene loadScene(){
        return null;
    }

    public static Scene createScene(String name){
        Scene scene = Scene.create(name);
        scenes.put(name, scene);
        return setActiveScene(name);
    }

}
