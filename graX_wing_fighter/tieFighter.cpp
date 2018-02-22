#include "tieFighter.h"

tieFighter::tieFighter()
{
	this->xPos = random(5, 119);
	this->xPos = random(5, 119);
}

tieFighter::~tieFighter()
{
}

void tieFighter::fly()
{
	if (live)
	{
		this->yPos++;
		if (this->yPos > 70)
		{
			this->yPos = 13;
			this->xPos = random(5, 119);
		}
	}
}

void tieFighter::draw(Adafruit_SH1106 *display)
{
	if (this->yPos > 11)
	{
		display->drawPixel(xPos, yPos, WHITE);
		display->drawPixel(xPos + 1, yPos, WHITE);

		for (int i = 0; i < 5; i++)
		{
			display->drawPixel(xPos - 1, yPos - 2 + i, WHITE);
			display->drawPixel(xPos + 2, yPos - 2 + i, WHITE);
		}
	}
}

void tieFighter::deleted(Adafruit_SH1106 *display)
{
	if (this->yPos > 11)
	{
		display->drawPixel(xPos, yPos, BLACK);
		display->drawPixel(xPos + 1, yPos, BLACK);

		for (int i = 0; i < 5; i++)
		{
			display->drawPixel(xPos - 1, yPos - 2 + i, BLACK);
			display->drawPixel(xPos + 2, yPos - 2 + i, BLACK);
		}
	}
}

void tieFighter::usun(Adafruit_SH1106 *display)
{
	display->drawPixel(xPos, yPos, BLACK);
	display->drawPixel(xPos + 1, yPos, BLACK);

	for (int i = 0; i < 5; i++)
	{
		display->drawPixel(xPos - 1, yPos - 2 + i, BLACK);
		display->drawPixel(xPos + 2, yPos - 2 + i, BLACK);
	}
}

bool tieFighter::isAlive()
{
	return live; //gdy live = true to zyje
}

int tieFighter::getDie(int xShoot, int yShoot, Adafruit_SH1106 *display)
{
	if ((this->xPos - 1 == xShoot && this->yPos + 2 == yShoot) )	//|| () || ((this->xPos == xShoot || this->xPos + 1) && this->yPos == yShoot))
	{
		live = false;// gdy zostal trafiony to umiera wiec flaga live=false
		usun(display);
		return 1;
	}
	else if (this->xPos + 2 == xShoot && this->yPos + 2 == yShoot)
	{
		live = false;
		usun( display);
		return 1;
	}
	else if (this->xPos==xShoot && this->yPos==yShoot)
	{
		live = false;
		usun(display);
		return 1;
	}
	else if (this->xPos+1 == xShoot && this->yPos == yShoot)
	{
		live = false;
		usun(display);
		return 1;
	}
	return 0;
}

void tieFighter::respawn()
{
	if (!isAlive())
	{
		live = true;
		yPos = 0;
		xPos = random(5, 119);
	}
}