/*
 * TransformComponent.cpp
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#include "TransformComponent.h"

namespace gtfx {

TransformComponent::TransformComponent() {
	SetDefaultName("TransformComponent");
	mPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	mSize = glm::vec3(DEFAULT_WIDGET_SIZE, DEFAULT_WIDGET_SIZE, 0);
	mPivot = glm::vec3(0.5f, 0.5f, 0.5f);
}

TransformComponent::~TransformComponent() {
	// TODO Auto-generated destructor stub
}



void TransformComponent::OnUpdate(double gameTime) {

}
const glm::vec3& TransformComponent::GetSize() const {
    return mSize;
}
void TransformComponent::SetSize(const glm::vec3& size) {
    SetSize(size.x, size.y, size.z);
}
void TransformComponent::SetSize(float width, float height, float depth) {
    mSize = glm::vec3(width, height, depth);
}
const glm::vec3& TransformComponent::GetPosition() const {
    return mPosition;
}
void TransformComponent::SetPosition(const glm::vec3& position) {
    SetPosition(position.x, position.y, position.z);
    printf("%s", position);
}
void TransformComponent::SetPosition(float x, float y, float z) {
    mPosition = glm::vec3(x, y, z);
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
} /* namespace gtfx */
