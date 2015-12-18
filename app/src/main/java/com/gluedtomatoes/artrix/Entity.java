package com.gluedtomatoes.artrix;

import android.graphics.Point;

/**
 * Created by gsarwal on 5/8/2015.
 */
public class Entity implements StateMachine {
    protected  State mCurrentState;
    protected  State mPreviousState;
    protected  State mGlobalState;

    public Node getNode() {
        return node;
    }

    public void setNode(Node node) {
        this.node = node;
    }

    protected Node node;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    protected  String name;
    protected boolean mIsInitialized;

    public boolean isInitialized() {
        return mIsInitialized;
    }
    @Override
    public State getCurrentState() {
        return mCurrentState;
    }

    @Override
    public State getPreviousState() {
        return mPreviousState;
    }

    @Override
    public State getGlobalState() {
        return mGlobalState;
    }

    @Override
    public void setCurrentState(State state) {
        if(state == null){
            state = NopState.state;
        }
        mCurrentState = state;
    }

    @Override
    public void setPreviousState(State state) {
        if(state == null){
            state = NopState.state;
        }
        mPreviousState = state;
    }

    @Override
    public void setGlobalState(State state) {
        if(state == null){
            state = NopState.state;
        }
        mGlobalState = state;
    }

    @Override
    public void changeState(State state) {
        StateManager.changeState(this, state);
    }
    @Override
    public void init(){
        mCurrentState = NopState.state;
    }
    @Override
    public void update(double gameTime){
        mCurrentState.update(this, gameTime);
    }
    @Override
    public void shutdown(){

    }
}
