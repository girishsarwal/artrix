#ifndef METRICSMANAGER_H
#define METRICSMANAGER_H
#include <android/log.h>
#include "Vector2.h"

class MetricsManager
{
    public:
        MetricsManager();
        virtual ~MetricsManager();
        static MetricsManager* GetInstance();
        static void DestroyInstance();
        void Initialize(float width, float height);
        void Calculate();

        Vector2& GetResolution();
        Vector2& GetQResolution();
        Vector2& GetQ1();
        Vector2& GetQ2();
        Vector2& GetQ3();
        Vector2& GetQ4();
        Vector2& GetTopLeft();
        Vector2& GetTopCenter();
        Vector2& GetTopRight();
        Vector2& GetMiddleLeft();
        Vector2& GetMiddleCenter();
        Vector2& GetMiddleRight();
        Vector2& GetBottomLeft();
        Vector2& GetBottomCenter();
        Vector2& GetBottomRight();


    protected:
    private:
        Vector2 mResolution;
        Vector2 mQResolution;
        /** POI **/
        Vector2 mQ1;
        Vector2 mQ2;
        Vector2 mQ3;
        Vector2 mQ4;
        Vector2 mTopLeft;
        Vector2 mTopCenter;
        Vector2 mTopRight;
        Vector2 mMiddleLeft;
        Vector2 mMiddleCenter;
        Vector2 mMiddleRight;
        Vector2 mBottomLeft;
        Vector2 mBottomCenter;
        Vector2 mBottomRight;

        static MetricsManager* mInstance;

};

#endif // METRICSMANAGER_H

