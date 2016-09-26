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

        void Calculate();

    protected:
    private:
        Vector2 mResolution;
        Vector2 mHalfResolution;
        /** POI **/
        Vector2 mQ1;
        Vector2 mQ2;
        Vector2 mQ3;
        Vector2 mQ4;
        Vector2 mTopLeft;
        Vector2 mTopCenter;
        Vector2 mTopRight;
        Vector2 mMiddeLeft;
        Vector2 mMiddleCenter;
        Vector2 mMiddleRight;
        Vector2 mBottomLeft;
        Vector2 mBottomCenter;
        Vector2 mBottomRight;

        static MetricsManager* mInstance;

};

#endif // METRICSMANAGER_H

