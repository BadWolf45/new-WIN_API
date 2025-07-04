#pragma once

class Scene
{
public:
	Scene() = default;
	~Scene() = default;

	virtual void Update() = 0;
	virtual void Render(HDC hdc) = 0;

	virtual void Start() {}
	virtual void End() {}
};
