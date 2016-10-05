#ifndef WIDGET_H
#define WIDGET_H
#include <stdio.h>
#include <string>
#include <sstream>
#include <tinyxml2.h>
#include "agk.h"
#include "Vector2.h"
#include "utils.h"
#include "statemachine.h"
#define DEFAULT_WIDGET_SIZE 100
using namespace std;
using namespace tinyxml2;
class Widget :
    public StateMachine
{
    public:
        /** constructors **/
        Widget();
        Widget(const Vector2&, const Vector2&);
        Widget(XMLNode*);

        virtual ~Widget();

        /** Properties **/

        bool GetIsInitialized() const;



        bool GetIsVisible() const;
        void SetIsVisible(bool);
        const Vector2& GetSize() const;
        void SetSize(const Vector2&);
        void SetSize(float, float);
        const Vector2& GetPosition() const;
        void SetPosition(const Vector2&);
        void SetPosition(float, float);
        const Vector2& GetPivot() const;
        void SetPivot(const Vector2&);
        void SetPivot(float, float);
        const string& GetName() const;
        void SetName(const string&);


        /** Lifecycle **/
        bool ValidateAttributes();
        void BeforeInitialize();
        void Initialize();
        void AfterInitialize();

        void Update();
        void Draw();

        /** Debug **/
        string dump() const;
        virtual void Print();
        friend ostream& operator<<(ostream& stream, const Widget& widget);

        bool operator==(const Widget& rhs) const;
        bool operator!=(const Widget& rhs) const;

    protected:
        string mName;
        Vector2 mPosition;
        Vector2 mPivot;
        Vector2 mSize;
        bool mIsVisible;

        /** property change hooks **/
        virtual void OnSetVisible();
        virtual void OnSetPosition();
        virtual void OnSetSize();

        /** lifecycle hooks **/
        virtual void OnBeforeInitialize();          /** use to setup resources required for initialization **/
        virtual void OnInitialize();                /** use for initialization **/
        virtual void OnAfterInitialize();           /** use for validating intialization was successfully carried out **/
        virtual void OnUpdate();
        virtual void OnDraw();

        string _str;
        bool mIsInitialized;
    private:
        static int nextId;
        void SetDefaultName();
};

#endif // WIDGET_H
