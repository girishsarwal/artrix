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
	mProgram->Use();
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

const std::string& RenderComponent::GetProgramName() const {
	return mProgramName;
}

const VertexDefinition& RenderComponent::GetVertexDefinition() const {
	return mVertexDefinition;
}

Program* RenderComponent::GetProgram() {
	return mProgram;
}

void RenderComponent::SetProgramName(const std::string& program) {
	mProgramName = program;
	mProgram = SPM->Get(mProgramName);
	mVertexDefinition = gtfx::VertexDefinitionManager::DetermineSuitableVertexFormat(mProgram);
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
	VertexColorTextureNormal::EnableAttribute(VertexColorTextureNormal::INDEX_POSITION);
	VertexColorTextureNormal::EnableAttribute(VertexColorTextureNormal::INDEX_COLOR);
	VertexColorTextureNormal::EnableAttribute(VertexColorTextureNormal::INDEX_TEX0);
	VertexColorTextureNormal::EnableAttribute(VertexColorTextureNormal::INDEX_NORMAL);
}
void RenderComponent::OnRender(double gameTime) {

	glBindBuffer(GL_ARRAY_BUFFER, mGeom->mVertexBufferId);
	glDrawElements(GL_TRIANGLES, mGeom->mSizeIndices, GL_UNSIGNED_INT, (void*)0);

}
void RenderComponent::OnAfterRender(double gameTime) {
	VertexColorTextureNormal::DisableAttribute(VertexColorTextureNormal::INDEX_POSITION);
	VertexColorTextureNormal::DisableAttribute(VertexColorTextureNormal::INDEX_COLOR);
	VertexColorTextureNormal::DisableAttribute(VertexColorTextureNormal::INDEX_TEX0);
	VertexColorTextureNormal::DisableAttribute(VertexColorTextureNormal::INDEX_NORMAL);
}

} /* namespace gtfx */
