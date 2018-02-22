/*
 Name:		graX_wing_fighter.ino
 Created:	2018-02-11 19:20:09
 Author:	MarcinSith
*/

// the setup function runs once when you press reset or power the board
#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SH1106.h>
#include "X_wing.h"
#include "shoot.h"
#include"tieFighter.h"


#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
B00000001, B11000000,
B00000001, B11000000,
B00000011, B11100000,
B11110011, B11100000,
B11111110, B11111000,
B01111110, B11111111,
B00110011, B10011111,
B00011111, B11111100,
B00001101, B01110000,
B00011011, B10100000,
B00111111, B11100000,
B00111111, B11110000,
B01111100, B11110000,
B01110000, B01110000,
B00000000, B00110000 };

#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

X_wing statek1;

shoot strzal1(statek1.get_xPos());
shoot strzal2;
//przyciski 
const int buttonLeft = 2;     
const int buttonRight = 3;
int buttonStateL = 0;         // variable for reading the pushbutton status
int buttonStateR = 0;

int wynik = 0;
int wynikOld = 0;
//-------------
tieFighter tie1, tie2;

int tieF5 = 0;

void setup() {
	pinMode(buttonLeft, INPUT);
	pinMode(buttonRight, INPUT);

	display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
	display.display();
	delay(2000);
	display.clearDisplay();

	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 0);

	display.print("SCORE: ");
	for (int i = 0; i < 125; i++)
	{
		display.drawPixel(i, 9, WHITE);
	}
	display.println();

}


void loop()
{
	//demo();
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(38, 0);
	display.print(wynik);

	strzelanie();

	if (tie1.isAlive()) //jesli zyje to rysuj 
	{
		tie1.draw(&display);
	}
	else
	{
		tie1.usun( &display);//jak nie to skasuj 
	}
	if (tie2.isAlive())
	{
		tie2.draw( &display);
	}
	else
	{
		tie2.usun( &display);
	}

	sterowanie();//pozwala na sterowanie statkiem przez uzycie przyciskow
	
	wynik+=tie1.getDie(strzal1.getX(), strzal1.getY(),&display);
	wynik+=tie1.getDie(strzal2.getX(), strzal2.getY(),&display);
	wynik += tie2.getDie(strzal1.getX(), strzal1.getY(), &display);
	wynik += tie2.getDie(strzal2.getX(), strzal2.getY(), &display);
	
	if (wynikOld != wynik)
	{
		display.setTextSize(1);
		display.setTextColor(BLACK);
		display.setCursor(38, 0);
		display.print(wynikOld);
	}	
	wynikOld = wynik;

	tie1.respawn();
	tie2.respawn();
	//spowalnia lot tie fightera
	if (tieF5 % 2 == 0)
	{
		if (tie1.isAlive())
		{
			tie1.deleted( &display);
			tie1.fly();
		}
		if (tie2.isAlive())
		{
			tie2.deleted( &display);
			tie2.fly();
		}
	}
	tieF5++;
	if (tieF5 > 9)tieF5 = 0;

}

void demo()
{

	for (int i = 0; i < 50; i++)
	{
		statek1.right(&display);
		strzal1.fire(&display);
		if (strzal1.isReady() == true)
		{
			strzal1.setX(statek1.get_xPos());
		}
		//----drugi strzal -----------------------------------------

		if (strzal1.getY() == 27)
		{
			strzal2.setX(statek1.get_xPos());
		}
		if (strzal2.isReady() == false && strzal2.getX() != NULL)
		{
			strzal2.fire(&display);
		}
	}
	//---------------
	for (int i = 0; i < 50; i++)
	{
		statek1.left(&display);
		strzal1.fire(&display);
		if (strzal1.isReady() == true)
		{
			strzal1.setX(statek1.get_xPos());
		}
		//----drugi strzal -----------------------------------------

		if (strzal1.getY() == 27)
		{
			strzal2.setX(statek1.get_xPos());
		}
		if (strzal2.isReady() == false && strzal2.getX() != NULL)
		{
			strzal2.fire(&display);
		}
	}
}

void sterowanie()
{
	buttonStateL = digitalRead(buttonLeft);
	buttonStateR = digitalRead(buttonRight);
	if (buttonStateL == HIGH)
	{
		statek1.left(&display);
	}
	else if (buttonStateR == HIGH)
	{
		statek1.right(&display);
	}
	else
	{
		statek1.draw(statek1.get_xPos(), &display); display.display(); statek1.deleted(statek1.get_xPos(), &display);
	}//*/
}

void strzelanie()
{
	{ // S T R Z E L A N I E---------------------- 
		strzal1.fire(&display);
		if (strzal1.isReady() == true)
		{
			strzal1.setX(statek1.get_xPos());
		}
		//----drugi strzal -----------------------------------------
		if (strzal1.getY() == 27)
		{
			strzal2.setX(statek1.get_xPos());
		}
		if (strzal2.isReady() == false && strzal2.getX() != NULL)
		{
			strzal2.fire(&display);
		}
	}
}


