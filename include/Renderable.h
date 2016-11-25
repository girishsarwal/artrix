#ifndef RENDERABLE_H
#define RENDERABLE_H
#include "afx.h"
#include "Geometry.h"
class Renderable {
	protected:
    	glm::vec3 mPosition;
    	glm::vec3 mPivot;
    	glm::vec3 mSize;
    	bool mIsVisible;

    	Geometry* mGeometry;
	public:
    	Renderable();
    	~Renderable();
		virtual void Render(double gameTime);
		virtual void OnBeforeRender(double gameTime);
		virtual void OnRender(double gameTime) = 0;
		virtual void OnAfterRender(double gameTime);

		bool GetIsVisible() const;
		void SetIsVisible(bool);
		const glm::vec3& GetSize() const;
		void SetSize(const glm::vec3&);
		void SetSize(float, float, float);
		const glm::vec3& GetPosition() const;
		void SetPosition(const glm::vec3&);
		void SetPosition(float, float, float);
		const glm::vec3& GetPivot() const;
		void SetPivot(const glm::vec3&);
		void SetPivot(float, float, float);

		Geometry* GetGeometry();

		/** property change hooks **/
	    virtual void OnSetVisible();
	    virtual void OnSetPosition();
	    virtual void OnSetSize();



		void EnqueueForRender();
};
#endif
