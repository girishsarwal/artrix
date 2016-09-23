#include "CompositeWidget.h"

CompositeWidget::CompositeWidget()
{
    //ctor
}
CompositeWidget::CompositeWidget(const Vector2& position, const Vector2& size)
    : Widget(position, size)
{

}
CompositeWidget::CompositeWidget(XMLNode* node)
    : Widget(node) {

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
string CompositeWidget::dump() const{
    stringstream ss;
    ss << *this;
    std::vector<Widget*>::const_iterator it = mChildren.begin();
    while(it != mChildren.end()){
        ss << (*it)->dump();
        it++;
    }
    return ss.str();
}
void CompositeWidget::Print() {
    __android_log_print(ANDROID_LOG_VERBOSE, "CompositeWidget", "%s", dump().c_str());
}

ostream& operator<<(ostream& stream, const CompositeWidget& compositeWidget){
    // add to stream
    return stream;
}

