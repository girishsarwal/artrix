#ifndef WIDGET_H
#define WIDGET_H
#include "afx.h"
#include "StateMachine.h"
#include "KeyManageable.h"
#include "Component.h"
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "KeyedManager.h"

namespace gtfx {
class StateMachine;
class Component;
class GameObject :
    public StateMachine,
	public KeyManageable
{
    public:
        /** constructors **/
		GameObject();
		GameObject(tinyxml2::XMLNode*);

        virtual ~GameObject();

        /** Properties **/

        bool GetIsInitialized() const;

        /** Lifecycle **/
        virtual bool ValidateAttributes();
        void BeforeInitialize();
        void Initialize();
        void AfterInitialize();

        void BeforeUpdate(double frameTime);
        void Update(double);
        void AfterUpdate(double frameTime);

        void BeforeDestroy();
        void Destroy();
        void AfterDestroy();

        /** Debug **/
        string dump() const;
        virtual void Print();
        friend ostream& operator<<(ostream& stream, const GameObject& widget);

        bool operator==(const GameObject& rhs) const;
        bool operator!=(const GameObject& rhs) const;

    protected:


		/** lifecycle hooks **/
		virtual void OnBeforeInitialize();          /** use to setup resources required for initialization **/
		virtual void OnInitialize() = 0;            /** use for initialization **/
		virtual void OnAfterInitialize();           /** use for validating intialization was successfully carried out **/
		virtual void OnBeforeUpdate(double frameTime);
		virtual void OnUpdate(double) = 0;
		virtual void OnAfterUpdate(double frameTime);
		virtual void OnBeforeDestroy();
		virtual void OnDestroy();
		virtual void OnAfterDestroy();

        std::string _str;
        bool mIsInitialized;

        std::vector<gtfx::Component*> mComponents;
};
}
#endif // WIDGET_H
