#include "Vector2.h"

using namespace std;

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

void Vector2::Set(float _x, float _y) {
    x = _x;
    y = _y;
}

Vector2::~Vector2() {
    //dtor
}


float Vector2::Length() {
    return sqrt(LengthSq());
}

float Vector2::LengthSq() {
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

Vector2 Vector2::GetRight(const Vector2 &rhs) {
    return Vector2(-rhs.y, rhs.x);
}

Vector2 Vector2::GetLeft(const Vector2 &rhs) {
    return Vector2(rhs.y, -rhs.x);
}

string Vector2::ToString() {
    _str.clear();
    stringstream ss;
    ss << "{ x=" << x << ", ";
    ss << "y=" << y << " }";
    _str = ss.str();
    return _str;
}

void Vector2::Print() {
    string s = ToString();
    __android_log_print(ANDROID_LOG_VERBOSE, s.c_str(), "");
    //agk::Print(s.c_str());
}



