#pragma once

class Circle : public GameObject
{
public:
	Circle();
	Circle(float radius);
	~Circle();

	void Render(HDC hdc);
	bool isColisionPoint(Vector2 point);
	bool isColisionCircle(Circle* circle);



	float GetRadius() { return radius; }
protected:

	bool  isKeyDown = false;
	float radius;
	
};
