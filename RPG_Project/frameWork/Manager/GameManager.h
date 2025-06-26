#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Update();
	void Render();

	void Create();
	void Relese();

private:
	HDC hdc;

	HDC backBuffer;
	HBITMAP backBufferBitmap;
};
