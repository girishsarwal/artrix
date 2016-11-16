/*
 * Vector2.cpp
 *
 *  Created on: 11-Nov-2016
 *      Author: gsarwal
 */


#include "Vector3.h"

Vector3::Vector3() {
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Vector3::Vector3(const Vector3& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}

Vector3::Vector3(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

Vector3::Vector3(tinyxml2::XMLNode* node) {
    tinyxml2::XMLElement* element = node->ToElement();
    if(NULL != element){
        Set(atof(element->Attribute("x")), atof(element->Attribute("y")), atof(element->Attribute("y")));
    } else Set(0.0f, 0.0f, 0.0f);
}

void Vector3::Set(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
    Print();
}



Vector3::~Vector3() {
    //dtor
}


float Vector3::Length() const {
    return sqrt(LengthSq());
}

float Vector3::LengthSq() const {
    return (x*x + y*y);
}

void Vector3::Normalize() {
    float mag = LengthSq();
    x = x/mag;
    y = y/mag;
}

float Vector3::Dot(const Vector3& rhs) {
    return 0;
}

const Vector3 Vector3::GetRight() const {
    return Vector3(-this->y, this->x, 0.0f);
}

const Vector3 Vector3::GetLeft() const {
    return Vector3(this->y, -this->y, 0.0f);
}
void Vector3::Add(const Vector3& rhs) {
    x += rhs.x;
    y += rhs.y;
}

void Vector3::Translate(const Vector3& rhs) {
    Add(rhs);
}
void Vector3::Scale(float scalar) {
    x *= scalar;
    y *= scalar;
}
void Vector3::Print() {

    printf("Vector3::%s", dump().c_str());
}

std::string Vector3::dump() const{
    std::stringstream stream;
    stream << *this;
    return stream.str();
}

std::ostream& operator<<(std::ostream& stream, const Vector3& vec){
    stream << "\n<vec x=\"" << vec.x << "\" y=\"" << (vec.y) << "\" z=\"" << (vec.z) << "\"></vec>";
    return stream;
}

