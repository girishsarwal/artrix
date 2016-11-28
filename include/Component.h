/*
 * Component.h
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_COMPONENT_H_
#define INCLUDE_COMPONENT_H_

namespace gtfx {

class Component {
private:
	bool mIsEnabled;

public:
	Component();
	virtual void Update(double gameTime);
	virtual ~Component();

	bool GetIsEnabled() const;
	void SetIsEnabled(bool isEnabled);
};

} /* namespace gtfx */

#endif /* INCLUDE_COMPONENT_H_ */
