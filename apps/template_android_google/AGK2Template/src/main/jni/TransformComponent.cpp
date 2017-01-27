/*
 * TransformComponent.cpp
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#include "TransformComponent.h"

namespace gtfx {

TransformComponent::TransformComponent()
	: mParent (NULL) {
	SetDefaultName("TransformComponent");
	mPosition = Vector2(0.0f, 0.0f);
	mSize = Vector2(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE);
	mPivot = Vector2(0.5f, 0.5f);
}

TransformComponent::~TransformComponent() {

}



void TransformComponent::OnUpdate(double gameTime) {
	UpdateTransformationMatrix();
}
const Vector2& TransformComponent::GetSize() const {
    return mSize;
}
void TransformComponent::SetSize(const Vector2& size) {
    SetSize(size.x, size.y);
}
void TransformComponent::SetSize(float width, float height) {
    mSize = Vector2(width, height);
}
const Vector2& TransformComponent::GetPosition() const {
    return mPosition;
}
void TransformComponent::SetPosition(const Vector2& position) {
    SetPosition(position.x, position.y);
}
void TransformComponent::SetPosition(float x, float y) {
    mPosition = Vector2(x, y);
}


const Vector2& TransformComponent::GetPivot() const {
    return mPivot;
}
void TransformComponent::SetPivot(const Vector2& pivot) {
    SetPivot(pivot.x, pivot.y);
}
void TransformComponent::SetPivot(float pivotX, float pivotY) {
    mPivot = Vector2(pivotX, pivotY);
}

void TransformComponent::UpdateTransformationMatrix() {

}

gtfx::TransformComponent* TransformComponent::GetParent() {
	return mParent;
}

void TransformComponent::AddChild(TransformComponent* childTransform) {
	childTransform->SetParent(this);
	mChildren.push_back(childTransform);
}

const Vector2& TransformComponent::GetWorld() const {
	return mWorld;
}

void TransformComponent::SetParent(gtfx::TransformComponent* parent) {
	mParent = parent;
}

const Vector2& TransformComponent::GetLocal() const {
	return mLocal;
}

} /* namespace gtfx */

