package com.gluedtomatoes.artrix;

/**
 * Created by gsarwal on 5/18/2015.
 */
public class SplashState implements State{
    public static SplashState state = new SplashState();
    private Scene visual;
    private Sprite background = new Sprite("test.png");

    @Override
    public void init(StateMachine sm) {
        background.init();
        visual = SceneManager.createScene("SplashScene");
        visual.getRoot().createChild("background", background);
    }

    @Override
    public void enter(StateMachine sm) {

    }

    @Override
    public void update(StateMachine sm, double gameTime) {
        visual.update(gameTime);
    }

    @Override
    public void exit(StateMachine sm) {

    }
}