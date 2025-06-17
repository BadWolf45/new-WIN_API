#include "framework.h"

Circle::Circle()
{
}

Circle::Circle(float radius) : radius(radius)
{

}

Circle::~Circle()
{
}

void Circle::Render(HDC hdc)
{
	if (!isActive) { return; }
	Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}

bool Circle::isColisionPoint(POINT point)
{
	int dx = center.x - point.x;
	int dy = center.y - point.y;

	//float distance = sqrt(dx * dx + dy * dy);
	return (dx * dx + dy * dy) <= (radius * radius);
}

bool Circle::isColisionCircle(Circle* circle)
{
	int dx = center.x - circle->center.x;
	int dy = center.y - circle->center.y;

	//float distance = sqrt(dx * dx + dy * dy);
	return (dx * dx + dy * dy) <= ((radius + circle->radius) * (radius+ circle->radius));
}
