#pragma once

class Circle
{
public:
	Circle();
	Circle(float radius);
	~Circle();

	void Render(HDC hdc);
	bool isColisionPoint(Vector2 point);
	bool isColisionCircle(Circle* circle);

	void SetActive(bool active) { isActive = active; }
	bool GetActive() { return isActive; }
	void SetCenter(Vector2 center) { center = center; }
	void SetCenter(float x, float y) { center.x = x, center.y = y; }
	Vector2 GetCenter() { return center; }
	float GetRadius() { return radius; }
protected:
	bool isActive = true;
	bool  isKeyDown = false;
	float radius;
	Vector2 center = {};
};
