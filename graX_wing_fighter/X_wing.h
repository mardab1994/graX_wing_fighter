#pragma once
#ifndef XWING_h
#define XWING_h

#include <Arduino.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include"Naglowki.h"
//#include <Adafruit_GFX.h>
//#include <Adafruit_SH1106.h>


class X_wing
{
private:
	int xPos = 75;
	int yPos = 53;

	int xShoot=NULL;
	int yShoot=NULL;
	
public:
	X_wing();
	~X_wing();

	void draw(int x,Adafruit_SH1106 *display);
	void deleted(int x, Adafruit_SH1106 *display);

	void shoot(Adafruit_SH1106 *display);
	void left(Adafruit_SH1106 *display);
	void right(Adafruit_SH1106 *display);

	int get_xPos();

};

#endif