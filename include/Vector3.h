#ifndef VECTOR3_H
#define VECTOR3_H
#include "afx.h"
class Vector3
{

    public:
        Vector3();
        Vector3(const Vector3&);
        Vector3(float, float, float);
        Vector3(tinyxml2::XMLNode* xml);

        virtual ~Vector3();

        void Set(float, float, float);
        float Length() const;
        float LengthSq() const;
        void Normalize();
        void Add (const Vector3&);
        void Translate(const Vector3&);
        void Scale(float);
        float Dot(const Vector3&);
        const Vector3 GetRight() const;
        const Vector3 GetLeft() const;
        void Print();

        float x;
        float y;
        float z;

        std::string dump() const;
        friend std::ostream& operator<<(std::ostream& stream, const Vector3& vec);
    protected:
    private:
        std::string _str;
};

#endif // VECTOR3_H
