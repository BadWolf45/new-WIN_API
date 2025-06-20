#include "framework.h"

gauge::gauge()
{
	
}

gauge::~gauge()
{
}

void gauge::Update()
{
}

void gauge::Render(HDC hdc)
{
	HBRUSH hGrayBrush = CreateSolidBrush(RGB(100, 100, 100));

	RECT rect = { center.x - 25, center.y - 5, center.x + 25, center.y + 5 }; // Define a RECT structure for the rectangle
	FillRect(hdc, &rect, hGrayBrush); // Pass the RECT structure and brush to FillRect
	DeleteObject(hGrayBrush); // Clean up the brush object

	//FillRect(hdc, 0, 0, gaugeWidth,gaugeHeight,hGrayBrush );


}
