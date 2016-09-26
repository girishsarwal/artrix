#ifndef VECTOR2_H
#define VECTOR2_H
#include <math.h>
#include <string>
#include <sstream>
#include "agk.h"
#include <android/log.h>
#include <tinyxml2.h>
using namespace std;
using namespace tinyxml2;
class Vector2
{

    public:
        Vector2();
        Vector2(const Vector2&);
        Vector2(float, float);
        Vector2(XMLNode* xml);

        virtual ~Vector2();

        void Set(float, float);
        float Length() const;
        float LengthSq() const;
        void Normalize();
        void Add (const Vector2&);
        void Translate(const Vector2&);
        void Scale(float);
        float Dot(const Vector2&);
        Vector2 GetRight() const;
        Vector2 GetLeft() const;
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
