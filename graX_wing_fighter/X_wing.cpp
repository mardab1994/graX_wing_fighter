#include "X_wing.h"



X_wing::X_wing(/*int X, int Y*/)
{
	//x = X;
	//y = Y;
}


X_wing::~X_wing()
{
}

void X_wing::draw(int x, Adafruit_SH1106 *display)
{
	display->drawPixel(x, yPos, WHITE);
	for (int i = 0; i<11; i++)
	{
		display->drawPixel(x, yPos + i - 1, WHITE);
		if (i>2)
		{
			display->drawPixel(x - 1, yPos + i, WHITE);
			display->drawPixel(x + 1, yPos + i, WHITE);
		}
	}
	for (int i = 0; i<11; i++)
	{
		display->drawPixel(x - 5 + i, yPos + 9, WHITE);
		display->drawPixel(x - 5 + i, yPos + 8, WHITE);
	}
	for (int i = 0; i<6; i++)
	{
		display->drawPixel(x - 5, yPos - i + 10, WHITE);
		display->drawPixel(x + 5, yPos - i + 10, WHITE);
	}
}

void X_wing::deleted(int x, Adafruit_SH1106 *display)
{

	display->drawPixel(x, yPos, BLACK);
	for (int i = 0; i<11; i++)
	{
		display->drawPixel(x, yPos + i - 1, BLACK);
		if (i>2)
		{
			display->drawPixel(x - 1, yPos + i, BLACK);
			display->drawPixel(x + 1, yPos + i, BLACK);
		}
	}
	for (int i = 0; i<11; i++)
	{
		display->drawPixel(x - 5 + i, yPos + 9, BLACK);
		display->drawPixel(x - 5 + i, yPos + 8, BLACK);
	}
	for (int i = 0; i<6; i++)
	{
		display->drawPixel(x - 5, yPos - i + 10, BLACK);
		display->drawPixel(x + 5, yPos - i + 10, BLACK);
	}
}

void X_wing::left(Adafruit_SH1106 *display)
{
	this->xPos -= 1;
	if (this->xPos <0) { this->xPos = 0; }
	draw(this->xPos, display);
	display->display();
	deleted(this->xPos, display);
}

void X_wing::right(Adafruit_SH1106 *display)
{
	this->xPos += 1;
	if (this->xPos > 120) { this->xPos = 120; }
	draw(this->xPos, display);
	display->display();
	deleted(this->xPos, display);
}

void X_wing::shoot(Adafruit_SH1106 *display)
{
	if (this->xShoot == NULL)
	{

	}
	else
	{
		if (yShoot > 9)
		{
			display->drawPixel(xShoot, yShoot, BLACK);
			yShoot--;
			display->drawPixel(xShoot, yShoot, WHITE);
		}
	}

}

int X_wing::get_xPos()
{
	return this->xPos;
}
