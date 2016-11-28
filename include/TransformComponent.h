/*
 * TransformComponent.h
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#ifndef SRC_TRANSFORMCOMPONENT_H_
#define SRC_TRANSFORMCOMPONENT_H_

#include <Component.h>

namespace gtfx {

class TransformComponent: public Component {
public:
	TransformComponent();
	virtual ~TransformComponent();
	virtual void Update(double gameTime);
};

} /* namespace gtfx */

#endif /* SRC_TRANSFORMCOMPONENT_H_ */
