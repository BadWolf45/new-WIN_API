#pragma once

class Bullet : public Circle
{
private:
	float bulletSpeed = 400;
public:

	Bullet(float radius);
	~Bullet();

	void Update();


	
	void Fire(Vector2 center, Vector2 direction = Vector2::Up());


private:
	Vector2 direction = Vector2::Up();
};
