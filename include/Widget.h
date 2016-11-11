#ifndef WIDGET_H
#define WIDGET_H
class StateMachine;
#include "afx.h"
#include "StateMachine.h"
#include "KeyManageable.h"
#include "Vector3.h"
#define DEFAULT_WIDGET_SIZE 100

class Widget :
    public StateMachine
{
    public:
        /** constructors **/
        Widget();
        Widget(const Vector3&, const Vector3&);
        Widget(tinyxml2::XMLNode*);

        virtual ~Widget();

        /** Properties **/

        bool GetIsInitialized() const;



        bool GetIsVisible() const;
        void SetIsVisible(bool);
        const Vector3& GetSize() const;
        void SetSize(const Vector3&);
        void SetSize(float, float, float);
        const Vector3& GetPosition() const;
        void SetPosition(const Vector3&);
        void SetPosition(float, float, float);
        const Vector3& GetPivot() const;
        void SetPivot(const Vector3&);
        void SetPivot(float, float, float);



        /** Lifecycle **/
        bool ValidateAttributes();
        void BeforeInitialize();
        void Initialize();
        void AfterInitialize();

        void Update(double);
        void Draw(double);

        /** Debug **/
        string dump() const;
        virtual void Print();
        friend ostream& operator<<(ostream& stream, const Widget& widget);

        bool operator==(const Widget& rhs) const;
        bool operator!=(const Widget& rhs) const;

    protected:
        Vector3 mPosition;
        Vector3 mPivot;
        Vector3 mSize;
        bool mIsVisible;

        /** property change hooks **/
        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();

        /** lifecycle hooks **/
        virtual void OnBeforeInitialize();          /** use to setup resources required for initialization **/
        virtual void OnInitialize();                /** use for initialization **/
        virtual void OnAfterInitialize();           /** use for validating intialization was successfully carried out **/
        virtual void OnUpdate(double);
        virtual void OnDraw(double);

        std::string _str;
        bool mIsInitialized;
};

#endif // WIDGET_H
