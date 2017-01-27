/*
 * TransformComponent.h
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#ifndef SRC_TRANSFORMCOMPONENT_H_
#define SRC_TRANSFORMCOMPONENT_H_
#define DEFAULT_WIDGET_SIZE 100
#include <vector>
#include "Component.h"
#include "KeyManageable.h"
#include "Vector2.h"
namespace gtfx {
class TransformComponent:
		public Component {
protected:

	Vector2 mPosition;
	Vector2  mPivot;
	Vector2  mSize;

	Vector2 mLocal;
	Vector2 mWorld;
	TransformComponent* mParent;

	std::vector<TransformComponent*> mChildren;

public:

	TransformComponent();
	virtual ~TransformComponent();
	void OnUpdate(double gameTime);

	const Vector2& GetSize() const;
	void SetSize(const Vector2&);
	void SetSize(float, float);
	const Vector2& GetPosition() const;
	void SetPosition(const Vector2&);
	void SetPosition(float, float);
	const Vector2& GetPivot() const;
	void SetPivot(const Vector2&);
	void SetPivot(float, float);
	void UpdateTransformationMatrix();
	const Vector2& GetLocal() const;
	const Vector2& GetWorld() const;
	void AddChild(TransformComponent*);
	TransformComponent* GetParent();
	void SetParent(TransformComponent* parent);
};

} /* namespace gtfx */

#endif /* SRC_TRANSFORMCOMPONENT_H_ */
