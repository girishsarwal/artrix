#ifndef RENDERABLE_H
#define RENDERABLE_H
#include "afx.h"
#include "Vector3.h"
class Renderable {
	protected:
    	Vector3 mPosition;
    	Vector3 mPivot;
    	Vector3 mSize;
    	bool mIsVisible;

	public:
    	Renderable();
    	~Renderable();
		virtual void Render(double gameTime);
		virtual void OnBeforeRender(double gameTime);
		virtual void OnRender(double gameTime) = 0;
		virtual void OnAfterRender(double gameTime);

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

		/** property change hooks **/
	    virtual void OnSetVisible();
	    virtual void OnSetPosition();
	    virtual void OnSetSize();



		void EnqueueForRender();
};
#endif
