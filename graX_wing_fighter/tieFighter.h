#pragma once
#ifndef TIE_
#define TIE_

#include "Naglowki.h"

class tieFighter
{
private:
	int xPos;
	int yPos =13;
	bool live = true;
public:
	void fly();
	void draw(Adafruit_SH1106 *display);
	void deleted( Adafruit_SH1106 *display);
	void usun(Adafruit_SH1106 *display);
	bool isAlive();
	int getDie(int xShoot, int yShoot, Adafruit_SH1106 *display);
	void respawn();

	tieFighter();
	~tieFighter();
};

#endif

