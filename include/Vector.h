#pragma once
struct Vector{
	float x;
	float y;
	Vector(float _x, float _y){
		x = _x;
		y = _y;
	}
	Vector(){
	}
	~Vector(){
	}
	float getMagnitude(){
		return sqrt(x * x + y * y);
	}
};
