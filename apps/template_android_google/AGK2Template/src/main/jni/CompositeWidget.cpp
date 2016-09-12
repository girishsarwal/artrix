#include "CompositeWidget.h"

CompositeWidget::CompositeWidget()
{
    //ctor
}
CompositeWidget::CompositeWidget(Vector2& position, Vector2& size)
    : Widget(position, size)
{

}
CompositeWidget::~CompositeWidget()
{
    //dtor
}
void CompositeWidget::AddWidget()
{

}

void CompositeWidget::RemoveWidget(std::string& _name)
{

}

Widget* CompositeWidget::GetWidget(std::string& _name)
{

}

void CompositeWidget::Update()
{
    std::vector<Widget*>::iterator it = mChildren.begin();
    while(it != mChildren.end()){
        (*it)->Update();
        it++;
    }
}
