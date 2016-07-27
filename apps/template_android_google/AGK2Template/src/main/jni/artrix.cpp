#include "artrix.h"

Artrix::Artrix()
{

}

Artrix::~Artrix()
{
    //dtor
}
void Artrix::begin()
{
    StateManager::GetInstance();
}

void Artrix::update()
{

}
void Artrix::shutdown()
{
    StateManager::DestroyInstance();
}
