#pragma once

class Bullet : public Circle
{
private:
	float bulletSpeed = 0.1;
public:

	Bullet(float radius);
	~Bullet();

	void Update();


	
	void Fire(Vector2 center);


private:
};
