#include "Widget.h"
#include "Component.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
namespace gtfx {
Widget::Widget() {
	mIsInitialized = false;
    SetDefaultName(string("Widget"));
}


Widget::Widget(tinyxml2::XMLNode* node) {
	mIsInitialized = false;
    SetDefaultName(string("Widget"));
}

Widget::~Widget() {

}

bool Widget::GetIsInitialized() const {
    return mIsInitialized;
}
void Widget::Initialize() {
	BeforeInitialize();
    OnInitialize();             /** we let the dervied class function execute first **/
    std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
    	while(component != mComponents.end()){
    		(*component)->Initialize();
    		component++;
    }
    mIsInitialized = true;
    AfterInitialize();
}



void Widget::BeforeInitialize() {
	OnBeforeInitialize();
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
	while(component != mComponents.end()){
		(*component)->BeforeInitialize();
		component++;
	}
}
void Widget::AfterInitialize() {
	Print();
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
    while(component != mComponents.end()){
    	(*component)->AfterInitialize();
    	component++;
    }
    OnAfterInitialize();
}



void Widget::Update(double gameTime) {
	if(!mIsInitialized){
		Initialize();
	}
    OnUpdate(gameTime);
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
    while(component != mComponents.end()){
    	(*component)->Update(gameTime);
    	component++;
    }
}


void Widget::Destroy() {

	BeforeDestroy();
    OnDestroy();             /** we let the dervied class function execute first **/

    mIsInitialized = true;
    AfterInitialize();
}



void Widget::BeforeDestroy() {
	OnBeforeDestroy();
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
	while(component != mComponents.end()){
		(*component)->BeforeDestroy();
		component++;
	}
}
void Widget::AfterDestroy() {
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
    while(component != mComponents.end()){
    	(*component)->AfterDestroy();
    	component++;
    }
	OnAfterDestroy();
}

void Widget::OnBeforeInitialize() { printf("Widget::OnBeforeInitialize - base was called"); }
void Widget::OnInitialize() { printf("Widget::OnBeforeInitialize - base was called"); }
void Widget::OnAfterInitialize() {
	printf("Widget::OnAfterInitialize - base was called"); }

void Widget::OnBeforeUpdate(double gameTime) { }
void Widget::OnUpdate(double gameTime) { }
void Widget::OnAfterUpdate(double gameTime) { }
void Widget::OnBeforeDestroy() { }
void Widget::OnDestroy() { }
void Widget::OnAfterDestroy() { }

string Widget::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void Widget::Print() {
    printf("Widget - %s", dump().c_str());
}

ostream& operator<<(ostream& stream, const Widget& widget) {
    stream << "<widget type=\"undefined\" name =\"" << widget.mName.c_str() << "\">\n";
    //inject components
    stream << "</widget>";
    return stream;
}



bool Widget::operator==(const Widget& rhs) const {
    return (this->mName == rhs.mName);
};
bool Widget::operator!=(const Widget& rhs) const {
    return !(*this == rhs);
};
bool Widget::ValidateAttributes() {
	return true;
}
}
