#pragma once

struct Vector2
{

	float x;
	float y;

	Vector2() : x(0), y(0)
	{}
	Vector2(float x, float y) : x(x), y(y)
	{}

	Vector2 operator+(const Vector2& other) const // 연산자 오버로딩(연산자의 재정의)(사용자 정의 자료형의 연산자 재정의)
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator- (const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator* (const float& scala)
	{
		return Vector2(x * scala, y * scala);
	}

	void operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
	}

	void operator-= (const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
	}

	void operator*= (const float& scala)
	{
		x *= scala;
		y *= scala;
	}

	float Magnitude() const	{ return sqrtf(x * x + y * y); }
	float strMagnitude() const { return x * x + y * y; }

	void Nomalize()
	{
		float lenght = Magnitude();

		if (lenght > 0)
		{
			x /= lenght;
			y /= lenght;
		}
	}

	Vector2 GetNomalize()
	{
		float lenght = Magnitude();
		return Vector2(x / lenght, y / lenght);
	}

	static Vector2 Zero() { return Vector2(0, 0); }
	static Vector2 One() { return Vector2(1, 1); }

	static Vector2 Right() { return Vector2(1, 0); }
	static Vector2 Left() { return Vector2(-1, 0); }
	static Vector2 Up() { return Vector2(0, -1); }
	static Vector2 Down() { return Vector2(0, 1); }
};
