#include "MetricsManager.h"

MetricsManager::MetricsManager() {

}

MetricsManager::~MetricsManager() {

}

void MetricsManager::Calculate() {

    mQResolution.Set(mResolution.x/2, mResolution.y/2);
    mQ1.Set(mResolution.x * 3/4, mResolution.y * 1/4);
    mQ2.Set(mResolution.x * 3/4, mResolution.y * 3/4);
    mQ3.Set(mResolution.x * 1/4, mResolution.y * 3/4);
    mQ4.Set(mResolution.x * 1/4, mResolution.y * 1/4);

    mTopLeft.Set(0, 0);
    mTopCenter.Set(mQResolution.x, 0);
    mTopRight.Set(mResolution.x, 0);
    mMiddleLeft.Set(0, mQResolution.y);
    mMiddleCenter.Set(mQResolution.x, mQResolution.y);
    mMiddleRight.Set(mResolution.x, mQResolution.y);
    mBottomLeft.Set(0, mResolution.y);
    mBottomCenter.Set(mQResolution.x, mResolution.y);
    mBottomRight.Set(mResolution.x, mResolution.y);
}

void MetricsManager::Initialize(float width, float height) {
    mResolution = Vector2(width, height);
    Calculate();
}
MetricsManager* MetricsManager::GetInstance()
{
    if(0 == mInstance)
        mInstance = new MetricsManager();
    return mInstance;
}
void MetricsManager::DestroyInstance()
{
    delete(mInstance);
}

MetricsManager* MetricsManager::mInstance = NULL;


Vector2& MetricsManager::GetResolution() {
    return mResolution;
}

Vector2& MetricsManager::GetQResolution() {
    return mQResolution;
}

Vector2& MetricsManager::GetQ1() {
    return mQ1;
}

Vector2& MetricsManager::GetQ2() {
    return mQ2;
}

Vector2& MetricsManager::GetQ3() {
    return mQ3;
}

Vector2& MetricsManager::GetQ4() {
    return mQ4;
}

Vector2& MetricsManager::GetTopLeft() {
    return mTopLeft;
}

Vector2& MetricsManager::GetTopCenter() {
    return mTopCenter;
}

Vector2& MetricsManager::GetTopRight() {
    return mTopRight;
}

Vector2& MetricsManager::GetMiddleLeft() {
    return mMiddleLeft;
}

Vector2& MetricsManager::GetMiddleCenter() {
    return mMiddleCenter;
}

Vector2& MetricsManager::GetMiddleRight() {
    return mMiddleRight;
}

Vector2& MetricsManager::GetBottomLeft() {
    return mBottomLeft;
}

Vector2& MetricsManager::GetBottomCenter() {
    return mBottomCenter;
}

Vector2& MetricsManager::GetBottomRight() {
    return mBottomRight;
}
