#pragma once

class Bullet : public Circle
{
private:
	float bulletSpeed = 400;
public:

	Bullet(float radius);
	~Bullet();

	void Update();


	
	void Fire(Vector2 center,string tag, Vector2 direction = Vector2::Up());

	void SetTag(string tag) { this->tag = tag; }
	string GetTag() { return tag; }

private:
	string tag;
	Vector2 direction = Vector2::Up();


};
