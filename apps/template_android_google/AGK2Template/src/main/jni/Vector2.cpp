#include "Vector2.h"

Vector2::Vector2()
{
    x = 0.0f;
    y = 0.0f;
}
Vector2::Vector2(const Vector2& rhs)
{
    x = rhs.x;
    y = rhs.y;
}
Vector2::Vector2(float _x, float _y)
{
    x = _x;
    y = _y;
}

void Vector2::Set(float _x, float _y)
{
    x = _x;
    y = _y;
}


float Vector2::Length()
{
    return sqrt(LengthSq());
}

float Vector2::LengthSq()
{
    return (x*x + y*y);
}

void Vector2::Normalize()
{

}


Vector2::~Vector2()
{
    //dtor
}
