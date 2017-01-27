/*
 * RenderComponent.cpp
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#include "RenderComponent.h"

namespace gtfx {

RenderComponent::RenderComponent() 	{
	mIsVisible = true;
	SetDefaultName("RenderComponent");
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

void RenderComponent::SetTexture(std::string& texture) {
	mTexture = texture;
}

void RenderComponent::OnInitialize() {

}
void RenderComponent::OnUpdate(double gameTime) {
	Render(gameTime);
}

void RenderComponent::OnBeforeRender(double gameTime) {

}
void RenderComponent::OnRender(double gameTime) {

}
void RenderComponent::OnAfterRender(double gameTime) {
}

} /* namespace gtfx */
