#pragma once

#ifndef SHOOT_h
#define SHOOT_h

#include"Naglowki.h"

//#include "Adafruit_GFX.h"
//#include "Adafruit_SH1106.h"

class shoot
{
private:
	int yShoot = 52;//53
	int xShoot=NULL;

	bool readyToNextFire=false;//zmienna ktora pozwoli na ponowne wykorzystanie strzalu po osiagnieciu celu lub dojscia do konca linii

public:
	void fire(Adafruit_SH1106 *display);
	void setX(int x);
	int getY();
	int getX();
	bool isReady();
	shoot(int x);
	shoot();
	~shoot();
};


#endif
