package com.gluedtomatoes.artrix;

/**
 * Created by gsarwal on 5/8/2015.
 */
public interface State{
    public void init(StateMachine sm);
    public void enter(StateMachine sm);
    public void update(StateMachine sm, double gameTime);
    public void exit(StateMachine sm);
}
