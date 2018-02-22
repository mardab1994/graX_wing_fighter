#include "shoot.h"

shoot::shoot(int x)
{
	this->xShoot = x;
}
shoot::shoot() {}

shoot::~shoot()
{
}


void shoot::fire(Adafruit_SH1106 *display)
{
	if (yShoot > 9)
	{
		display->drawPixel(this->xShoot, yShoot, BLACK);
		this->yShoot--;
		display->drawPixel(this->xShoot, yShoot, WHITE);
	}
	else
	{
		readyToNextFire = true;
	}
}

void shoot::setX(int x)
{
	this->xShoot = x;
	yShoot = 52;
	readyToNextFire = false;
}

int shoot::getY()
{
	return this->yShoot;
}

int shoot::getX()
{
	return this->xShoot;
}

bool shoot::isReady()
{
	return readyToNextFire;
}




