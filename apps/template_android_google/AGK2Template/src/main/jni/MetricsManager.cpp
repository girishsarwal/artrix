#include "MetricsManager.h"

MetricsManager::MetricsManager() {
    Calculate();
}

MetricsManager::~MetricsManager() {

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
