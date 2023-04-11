/*
 Name:		test_3.ino
 Created:	4/9/2023 10:22:19 PM
 Author:	Langga
*/
#include "EasyNextionLibrary.h"  // Please download this library from https://github.com/Seithan/EasyNextionLibrary

#define LED_BUILTIN 32

EasyNex myNex(Serial);

int X=0;
// the setup function runs once when you press reset or power the board
void setup() {
	myNex.begin(9600);

}

// the loop function runs over and over again until power down or reset
void loop() {
	X++;
	if (X>100) {
		X = 0;
	}
	SendValue(X); // "X" adalah percentage battery. Iaitu value yg akan dihantar ke TFT display. "X" adalah interger.
	delay(1000);
}

void SendValue(int Value) {             // DONT CHANGE THIS CODE
	String TextVal;
	TextVal = String(Value) + "%";      // DONT CHANGE THIS CODE
	myNex.writeNum("j0.val", Value);    // DONT CHANGE THIS CODE
	myNex.writeStr("t0.txt", TextVal);  // DONT CHANGE THIS CODE
}										// DONT CHANGE THIS CODE
