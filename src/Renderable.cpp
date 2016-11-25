/*
 * Renderable.cpp
 *
 *  Created on: 18-Nov-2016
 *      Author: gsarwal
 */

#include "afx.h"
#include "Renderable.h"

Renderable::Renderable() {

};
Renderable::~Renderable() {

};
void Renderable::Render(double gameTime) {
	OnBeforeRender(gameTime);
	OnRender(gameTime);
	OnAfterRender(gameTime);
}
void Renderable::OnBeforeRender(double gameTime) {

}
void Renderable::OnAfterRender(double gameTime) {

}

void Renderable::EnqueueForRender() {

}
void Renderable::OnSetVisible() { printf("Renderable::OnSetVisible - base was called"); }
void Renderable::OnSetPosition() { printf("Renderable::OnSetPosition - base was called"); }
void Renderable::OnSetSize() { printf("Renderable::OnSetSize - base was called"); }

bool Renderable::GetIsVisible() const {
    return mIsVisible;
}
void Renderable::SetIsVisible(bool isVisible){
    mIsVisible = isVisible;
    OnSetVisible();
}
const glm::vec3& Renderable::GetSize() const {
    return mSize;
}
void Renderable::SetSize(const glm::vec3& size) {
    SetSize(size.x, size.y, size.z);
}
void Renderable::SetSize(float width, float height, float depth) {
    mSize = glm::vec3(width, height, depth);
    OnSetSize();
}
const glm::vec3& Renderable::GetPosition() const {
    return mPosition;
}
void Renderable::SetPosition(const glm::vec3& position) {
    SetPosition(position.x, position.y, position.z);
    printf("%s", position);
}
void Renderable::SetPosition(float x, float y, float z) {
    mPosition = glm::vec3(x, y, z);
    OnSetPosition();
}

const glm::vec3& Renderable::GetPivot() const {
    return mPivot;
}
void Renderable::SetPivot(const glm::vec3& pivot) {
    SetPivot(pivot.x, pivot.y, pivot.z);
}
void Renderable::SetPivot(float pivotX, float pivotY, float pivotZ) {
    mPivot = glm::vec3(pivotX, pivotY, pivotZ);
}

Geometry* Renderable::GetGeometry() {
	return mGeometry;
}
