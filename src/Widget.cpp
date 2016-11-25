#include "Widget.h"

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
    OnBeforeInitialize();

    OnInitialize();             /** we let the dervied class function execute first **/
    mIsInitialized = true;

    OnAfterInitialize();
}



void Widget::BeforeInitialize() {
    OnBeforeInitialize();
}
void Widget::AfterInitialize() {
	Print();
    OnAfterInitialize();
}



void Widget::Update(double gameTime) {
	if(!mIsInitialized){
		Initialize();
	}
    OnUpdate(gameTime);
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
