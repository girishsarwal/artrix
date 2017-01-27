/*
 * TransformComponent.h
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#ifndef SRC_TRANSFORMCOMPONENT_H_
#define SRC_TRANSFORMCOMPONENT_H_
#define DEFAULT_WIDGET_SIZE 100
#include "Component.h"
#include "KeyManageable.h"
namespace gtfx {

class TransformComponent:
		public Component {
protected:
	glm::vec3 mPosition;
	glm::vec3 mPivot;
	glm::vec3 mSize;

	glm::mat4 mTranslationMatrix;
	glm::mat4 mRotationMatrix;
	glm::mat4 mScalingMatrix;

	glm::mat4 mLocal;
	glm::mat4 mWorld;
	gtfx::TransformComponent* mParent;

	std::vector<gtfx::TransformComponent*> mChildren;

public:

	TransformComponent();
	virtual ~TransformComponent();
	void OnUpdate(double gameTime);

	const glm::vec3& GetSize() const;
	void SetSize(const glm::vec3&);
	void SetSize(float, float, float);
	const glm::vec3& GetPosition() const;
	void SetPosition(const glm::vec3&);
	void SetPosition(float, float, float);
	const glm::vec3& GetPivot() const;
	void SetPivot(const glm::vec3&);
	void SetPivot(float, float, float);
	void UpdateTransformationMatrix();
	const glm::mat4& GetLocal() const;
	const glm::mat4& GetWorld() const;
	void AddChild(TransformComponent*);
	gtfx::TransformComponent* GetParent();
	void SetParent(gtfx::TransformComponent* parent);
};

} /* namespace gtfx */

#endif /* SRC_TRANSFORMCOMPONENT_H_ */
