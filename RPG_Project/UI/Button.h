#pragma once
#include "framework.h"

class Button : public Rect
{
public:

	Button(Vector2 center, Vector2 size);
	~Button();

	enum class ButtonState
	{
		NORMAL,
		OVER,
		DOWN
	};

	void Update();
	void Render(HDC hdc);

	void SetText(wstring text) { this->text = text; }
	void SetOnClickListener(std::function<void()> listener) { this->onClick = listener;	}
private:
	wstring text = L"Butten";
	ButtonState currentState;
	bool prevLButtonDownState = false;
	function<void()> onClick;
};
