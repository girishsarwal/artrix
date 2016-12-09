#include "GameObject.h"
namespace gtfx {
GameObject::GameObject() {
	mIsInitialized = false;
    SetDefaultName(string("GameObject"));
}


GameObject::GameObject(tinyxml2::XMLNode* node) {
	mIsInitialized = false;
    SetDefaultName(string("GameObject"));
}

GameObject::~GameObject() {

}

bool GameObject::GetIsInitialized() const {
    return mIsInitialized;
}
void GameObject::Initialize() {
	BeforeInitialize();
    OnInitialize();             /** we let the dervied class function execute first **/
    std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
    	while(component != mComponents.end()){
    		(*component)->SetGameObject(this);
    		(*component)->Initialize();
    		component++;
    }
    mIsInitialized = true;
    AfterInitialize();
}



void GameObject::BeforeInitialize() {
	OnBeforeInitialize();
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
	while(component != mComponents.end()){
		(*component)->BeforeInitialize();
		component++;
	}
}
void GameObject::AfterInitialize() {
	Print();
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
    while(component != mComponents.end()){
    	(*component)->AfterInitialize();
    	component++;
    }
    OnAfterInitialize();
}



void GameObject::Update(double gameTime) {
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


void GameObject::Destroy() {

	BeforeDestroy();
    OnDestroy();             /** we let the dervied class function execute first **/

    mIsInitialized = true;
    AfterInitialize();
}



void GameObject::BeforeDestroy() {
	OnBeforeDestroy();
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
	while(component != mComponents.end()){
		(*component)->BeforeDestroy();
		component++;
	}
}
void GameObject::AfterDestroy() {
	std::vector<gtfx::Component*>::const_iterator component = mComponents.begin();
    while(component != mComponents.end()){
    	(*component)->AfterDestroy();
    	component++;
    }
	OnAfterDestroy();
}

void GameObject::OnBeforeInitialize() { printf("GameObject::OnBeforeInitialize - base was called"); }
void GameObject::OnInitialize() { printf("GameObject::OnBeforeInitialize - base was called"); }
void GameObject::OnAfterInitialize() {
	printf("GameObject::OnAfterInitialize - base was called"); }

void GameObject::OnBeforeUpdate(double gameTime) { }
void GameObject::OnUpdate(double gameTime) { }
void GameObject::OnAfterUpdate(double gameTime) { }
void GameObject::OnBeforeDestroy() { }
void GameObject::OnDestroy() { }
void GameObject::OnAfterDestroy() { }

string GameObject::dump() const{
    stringstream ss;
    ss << *this;
    return ss.str();
}

void GameObject::Print() {
    printf("GameObject - %s", dump().c_str());
}

ostream& operator<<(ostream& stream, const GameObject& GameObject) {
    stream << "<GameObject type=\"undefined\" name =\"" << GameObject.mName.c_str() << "\">\n";
    //inject components
    stream << "</GameObject>";
    return stream;
}



bool GameObject::operator==(const GameObject& rhs) const {
    return (this->mName == rhs.mName);
};
bool GameObject::operator!=(const GameObject& rhs) const {
    return !(*this == rhs);
};
bool GameObject::ValidateAttributes() {
	return true;
}
}
