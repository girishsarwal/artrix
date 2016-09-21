#include "Vector2.h"

Vector2::Vector2() {
    x = 0.0f;
    y = 0.0f;
}

Vector2::Vector2(const Vector2& rhs) {
    x = rhs.x;
    y = rhs.y;
}

Vector2::Vector2(float _x, float _y) {
    x = _x;
    y = _y;
}

Vector2::Vector2(XMLNode* node) {
    XMLElement* element = node->ToElement();
    if(NULL == element){
        Set(0, 0);
        return;
    }
    Set(atof(element->Attribute("x")), atof(element->Attribute("y")));
}

void Vector2::Set(float _x, float _y) {
    x = _x;
    y = _y;
}



Vector2::~Vector2() {
    //dtor
}


float Vector2::Length() const {
    return sqrt(LengthSq());
}

float Vector2::LengthSq() const {
    return (x*x + y*y);
}

void Vector2::Normalize() {
    float mag = LengthSq();
    x = x/mag;
    y = y/mag;
}

float Vector2::Dot(const Vector2& rhs) {
    return 0;
}

Vector2 Vector2::GetRight() const {
    return Vector2(-this->y, this->x);
}

Vector2 Vector2::GetLeft() const {
    return Vector2(this->y, -this->x);
}

void Vector2::Print() {

    __android_log_print(ANDROID_LOG_VERBOSE, "Vector2", "%s", dump().c_str());
}

string Vector2::dump() const{
    stringstream stream;
    stream << *this;
    return stream.str();
}

ostream& operator<<(ostream& stream, const Vector2& vec){
    stream << "{ x: " << vec.x << ", y: " << vec.y << " }";
    return stream;
}
