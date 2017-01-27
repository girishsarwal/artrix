/*
 * RenderComponent.h
 *
 *  Created on: 28-Nov-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_RENDERCOMPONENT_H_
#define INCLUDE_RENDERCOMPONENT_H_

#include "Component.h"
namespace gtfx {
class RenderComponent:
		public Component {

private:
	bool mIsVisible;
	std::string mTexture;
	int mAgkImageId;
	int mAgkSpriteId;

protected:


	virtual void OnBeforeRender(double gameTime);
	virtual void OnRender(double gameTime);
	virtual void OnAfterRender(double gameTime);

public:
	RenderComponent();
	virtual ~RenderComponent();

	bool GetIsVisible() const;
	void SetIsVisible(bool);

	void BeforeRender(double gameTime);
	void Render(double gameTime);				/** replace this with enqueueForRender **/
	void AfterRender(double gameTime);
	void OnInitialize();
	void OnUpdate(double gameTime);
	void SetTexture(std::string& texture);
};

} /* namespace gtfx */

#endif /* INCLUDE_RENDERCOMPONENT_H_ */
