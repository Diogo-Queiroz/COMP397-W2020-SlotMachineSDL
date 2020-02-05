#pragma once
#ifndef __PLANE__
#define __PLANE__
#include "DisplayObject.h"
#include "Move.h"

class Plane : public DisplayObject
{
public:
	Plane();
	~Plane();
	
	void draw() override;
	void update() override;
	void clean() override;

	void move(Move newMove);
private:
	float m_maxSpeed;
};

#endif /* defined (__PLANE__) */