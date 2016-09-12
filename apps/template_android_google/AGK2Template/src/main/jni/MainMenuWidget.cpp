#include "MainMenuWidget.h"

MainMenuWidget::MainMenuWidget()
{
    mPosition.Set(0, 0);
    mSize.Set(100, 300);
}

MainMenuWidget::~MainMenuWidget()
{
    //dtor
}
void MainMenuWidget::Update()
{
    //Update the buttons
    CompositeWidget::Update();
}

