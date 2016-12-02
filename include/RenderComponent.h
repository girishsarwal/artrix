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
#include "ShadingProgramManager.h"
#include "VertexDefinitionManager.h"
namespace gtfx {

class RenderComponent:
		public Component {

private:
	Geometry* mGeom;
	bool mIsVisible;

	std::string mProgramName;
	Program* mProgram;
	VertexDefinition mVertexDefinition;

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
	const std::string& GetProgramName() const;
	void SetProgramName(const std::string& program);
	Program* GetProgram();
	const VertexDefinition& GetVertexDefinition() const;
};

} /* namespace gtfx */

#endif /* INCLUDE_RENDERCOMPONENT_H_ */
