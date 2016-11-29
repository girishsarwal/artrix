/*
 * RenderComponent.h
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_RENDERCOMPONENT_H_
#define INCLUDE_RENDERCOMPONENT_H_

#include "Component.h"
#include "Geometry.h"
namespace gtfx {

class RenderComponent:
		public Component {

private:
	Geometry* mGeom;
	bool mIsVisible;

protected:


	virtual void OnBeforeRender(double gameTime);
	virtual void OnRender(double gameTime);
	virtual void OnAfterRender(double gameTime);

public:
	RenderComponent();
	virtual ~RenderComponent();


	bool GetIsVisible() const;
	void SetIsVisible(bool);

	void BeforeRender(double gameTime);
	void Render(double gameTime);
	void AfterRender(double gameTime);
	void OnInitialize();
	void OnUpdate(double gameTime);
	Geometry* GetGeometry() const;


};

} /* namespace gtfx */

#endif /* INCLUDE_RENDERCOMPONENT_H_ */
