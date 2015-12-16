package com.gluedtomatoes.artrix;

import java.util.HashMap;

/**
 * Created by gsarwal on 6/16/2015.
 */
public class SceneManager {
    private Entity Root;
    private static HashMap<String, Camera> cameras;

    public static Camera getActiveCamera() {
        return activeCamera;
    }

    public static void setActiveCamera(String camera) {
        activeCamera = cameras.get(camera);
    }

    private static Camera activeCamera;
    public void setAmbientLight(){

    }
    public Entity createMeshEntity(){
        return null;
    };
    public static Entity createCamera(String name, Vector4 position, Vector4 lookAt, float aspectRatio, float fov, float near, float far){
        Camera camera = Camera.create(name, position, lookAt, aspectRatio, fov, near, far);
        cameras.put(camera.name, camera);
        setActiveCamera(camera.getName());
        return camera;
    };
}
