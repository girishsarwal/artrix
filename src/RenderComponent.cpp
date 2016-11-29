/*
 * RenderComponent.cpp
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#include <RenderComponent.h>

namespace gtfx {

RenderComponent::RenderComponent() 	{
	mIsVisible = true;
	SetDefaultName("RenderComponent");
	mGeom = new Geometry();
}

RenderComponent::~RenderComponent() {
	// TODO Auto-generated destructor stub
}
void RenderComponent::BeforeRender(double gameTime) {
	OnBeforeRender(gameTime);
}
void RenderComponent::Render(double gameTime) {
	BeforeRender(gameTime);
	OnRender(gameTime);
	AfterRender(gameTime);
}
void RenderComponent::AfterRender(double gameTime) {
	OnAfterRender(gameTime);
}
Geometry* RenderComponent::GetGeometry() const {
	return mGeom;
}

void RenderComponent::OnInitialize() {
	glGenVertexArrays(1, &(mGeom->mVertexArrayId));
	glBindVertexArray(mGeom->mVertexArrayId);

	glGenBuffers(1, &(mGeom->mVertexBufferId));
	glBindBuffer(GL_ARRAY_BUFFER, mGeom->mVertexBufferId);
	glBufferData(GL_ARRAY_BUFFER, mGeom->mSizeVertices, mGeom->mVertexDataPtr, GL_STATIC_DRAW);


	glGenBuffers(1, &(mGeom->mIndexBufferId));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mGeom->mIndexBufferId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mGeom->mSizeIndices, mGeom->mIndicesDataPtr, GL_STATIC_DRAW);
}
void RenderComponent::OnUpdate(double gameTime) {
	Render(gameTime);
}

void RenderComponent::OnBeforeRender(double gameTime) {
	VertexColor::EnableAttribute(VertexColor::INDEX_POSITION);
	VertexColor::EnableAttribute(VertexColor::INDEX_COLOR);
}
void RenderComponent::OnRender(double gameTime) {

	glBindBuffer(GL_ARRAY_BUFFER, mGeom->mVertexBufferId);
	glDrawElements(GL_TRIANGLES, mGeom->mSizeIndices, GL_UNSIGNED_INT, (void*)0);

}
void RenderComponent::OnAfterRender(double gameTime) {
	VertexColor::DisableAttribute(VertexColor::INDEX_POSITION);
	VertexColor::DisableAttribute(VertexColor::INDEX_COLOR);
}

} /* namespace gtfx */
