#ifndef VECTOR2_H
#define VECTOR2_H
#include <math.h>
#include <string>
#include <sstream>
#include "agk.h"
#include <android/log.h>
using namespace std;
class Vector2
{

    public:
        Vector2();
        Vector2(const Vector2&);
        Vector2(float, float);
        virtual ~Vector2();

        void Set(float, float);
        float Length();
        float LengthSq();
        void Normalize();
        float Dot(const Vector2&);
        Vector2 GetRight(const Vector2&);
        Vector2 GetLeft(const Vector2&);
        void Print();

        float x;
        float y;

        string dump() const;
        friend ostream& operator<<(ostream& stream, const Vector2& vec);
    protected:
    private:
        string _str;
};

#endif // VECTOR2_H
