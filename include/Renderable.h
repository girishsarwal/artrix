#pragma once
#include "afx.h"
class Renderable{
	public:
		virtual void render(double gameTime) = 0;
		virtual void setDrawRectangle(float _left, float _top, float _width, float _height) = 0;
};
