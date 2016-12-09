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
	mPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	mSize = glm::vec3(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE, 0);
	mPivot = glm::vec3(0.5f, 0.5f, 0.5f);
}

TransformComponent::~TransformComponent() {

}



void TransformComponent::OnUpdate(double gameTime) {
	UpdateTransformationMatrix();
}
const glm::vec3& TransformComponent::GetSize() const {
    return mSize;
}
void TransformComponent::SetSize(const glm::vec3& size) {
    SetSize(size.x, size.y, size.z);
}
void TransformComponent::SetSize(float width, float height, float depth) {
    mSize = glm::vec3(width, height, depth);
	mScalingMatrix = glm::scale(glm::mat4(1.0f), mSize);

}
const glm::vec3& TransformComponent::GetPosition() const {
    return mPosition;
}
void TransformComponent::SetPosition(const glm::vec3& position) {
    SetPosition(position.x, position.y, position.z);
}
void TransformComponent::SetPosition(float x, float y, float z) {
    mPosition = glm::vec3(x, y, z);
    mTranslationMatrix = glm::translate(glm::mat4(1.0f), mPosition);
}


const glm::vec3& TransformComponent::GetPivot() const {
    return mPivot;
}
void TransformComponent::SetPivot(const glm::vec3& pivot) {
    SetPivot(pivot.x, pivot.y, pivot.z);
}
void TransformComponent::SetPivot(float pivotX, float pivotY, float pivotZ) {
    mPivot = glm::vec3(pivotX, pivotY, pivotZ);
}

void TransformComponent::UpdateTransformationMatrix() {
	mLocal = mTranslationMatrix * mRotationMatrix * mScalingMatrix;
	//mLocal = mScalingMatrix * mRotationMatrix * mTranslationMatrix;
	if(mParent == NULL) {
		mWorld = mLocal;
	} else mWorld = mLocal * mParent->mWorld;
}

gtfx::TransformComponent* TransformComponent::GetParent() {
	return mParent;
}

void TransformComponent::AddChild(TransformComponent* childTransform) {
	childTransform->SetParent(this);
	mChildren.push_back(childTransform);
}

const glm::mat4& TransformComponent::GetWorld() const {
	return mWorld;
}

void TransformComponent::SetParent(gtfx::TransformComponent* parent) {
	mParent = parent;
}

const glm::mat4& TransformComponent::GetLocal() const {
	return mLocal;
}

} /* namespace gtfx */

