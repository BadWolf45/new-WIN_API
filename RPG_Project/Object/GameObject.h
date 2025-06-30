#pragma once
#include "framework.h"

class GameObject
{
public:
	GameObject() = default;
	GameObject(Vector2 center) : center(center) {}

	
	~GameObject() = default;



	void SetCenter(Vector2 center) { center = center; }
	void SetCenter(float x, float y) { center.x = x, center.y = y; }
	Vector2 GetCenter() { return center; }
	void SetActive(bool active) { isActive = active; }
	bool GetActive() { return isActive; }

protected:
	bool isActive = true;
	Vector2 center = {};
};