/*
 Name:		test_3.ino
 Created:	4/9/2023 10:22:19 PM
 Author:	Langga
*/
#include "EasyNextionLibrary.h"  // Please download this library from https://github.com/Seithan/EasyNextionLibrary

#define LED_BUILTIN 32

EasyNex myNex(Serial);

int X=0;
int V=50;
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
	SendSOC(X); // "X" adalah percentage battery. Iaitu value yg akan dihantar ke TFT display. "X" adalah interger.
	SendVoltage(V); // "V" adalah Voltage. "V" adalah interger.
	delay(1000);
}

void SendSOC(int Value) {             // DONT CHANGE THIS CODE
	String TextVal;
	TextVal = "SOC: " + String(Value) + " %";      // DONT CHANGE THIS CODE
	myNex.writeNum("j0.val", Value);    // DONT CHANGE THIS CODE
	myNex.writeStr("t0.txt", TextVal);  // DONT CHANGE THIS CODE
}										// DONT CHANGE THIS CODE

void SendVoltage(int Value) {             // DONT CHANGE THIS CODE
	String TextVal;
	TextVal = "V: " + String(Value) + " V";      // DONT CHANGE THIS CODE
	myNex.writeStr("t1.txt", TextVal);  // DONT CHANGE THIS CODE
}
