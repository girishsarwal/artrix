#include "MetricsManager.h"

MetricsManager::MetricsManager()
{
    //ctor
}

MetricsManager::~MetricsManager()
{
    //dtor
}

void MetricsManager::Calculate() {

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
