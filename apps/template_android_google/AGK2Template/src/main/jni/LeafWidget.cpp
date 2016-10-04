#include "LeafWidget.h"

LeafWidget::LeafWidget(){

}

LeafWidget::~LeafWidget(){
    //dtor
}
LeafWidget::LeafWidget(const Vector2& position, const Vector2& size)
    : Widget(position, size)
{

}
LeafWidget::LeafWidget(XMLNode* node)
    : Widget(node)
{

}

