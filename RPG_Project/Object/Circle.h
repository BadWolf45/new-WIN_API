#pragma once

class Circle
{
public:
	Circle();
	Circle(float radius);
	~Circle();

	void Render(HDC hdc);
	bool isColisionPoint(POINT point);
	bool isColisionCircle(Circle* circle);

	void SetActive(bool active) { isActive = active; }
	bool GetActive() { return isActive; }
	void SetCenter(float2 center) { center = center; }
	float2 GetCenter() { return center; }
protected:
	bool isActive = true;
	bool  isKeyDown = false;
	float radius;
	float2 center = {};
};
