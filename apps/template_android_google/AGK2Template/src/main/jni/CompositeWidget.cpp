#include "CompositeWidget.h"

CompositeWidget::CompositeWidget()
{
    //ctor
}
CompositeWidget::CompositeWidget(const Vector2& position, const Vector2& size)
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
string CompositeWidget::ToString(){
    _str.clear();
    stringstream ss;
    ss<< Widget::ToString();
    std::vector<Widget*>::iterator it = mChildren.begin();
    while(it != mChildren.end()){
        ss << (*it)->ToString();
        it++;
    }
    _str = ss.str();
    return _str;
}
void CompositeWidget::Print() {
    string s = ToString();
    agk::Print(s.c_str());
}

