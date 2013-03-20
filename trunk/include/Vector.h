#pragma once
struct Vector{
	float x;
	float y;
	float z;
	Vector(float _x, float _y, float _z){
		x = _x;
		y = _y;
		z = _z;
	};
	Vector(float _x, float _y){
		x = _x;
		y = _y;
		z = 0;
	}
	Vector(){
	}
	~Vector(){
	}
	float getMagnitude(){
		return sqrt(x * x + y * y);
	}
};
