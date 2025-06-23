#pragma once

struct Vector2
{

	float x;
	float y;

	Vector2() : x(0), y(0)
	{}
	Vector2(float x, float y) : x(x), y(y)
	{}

	Vector2 operator+(const Vector2& other) const // ������ �����ε�(�������� ������)(����� ���� �ڷ����� ������ ������)
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator* (const float* scala)
	{
		return Vector2(x * scala.x, y * scala.y)
	}

	void operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
	}

	static Vector2 Zero() { return Vector2(0, 0); }
	static Vector2 One() { return Vector2(1, 1); }

	static Vector2 Right() { return Vector2(1, 0); }
	static Vector2 Left() { return Vector2(-1, 0); }
	static Vector2 Up() { return Vector2(0, -1); }
	static Vector2 Down() { return Vector2(0, 1); }
};
