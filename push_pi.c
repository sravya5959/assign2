//In this mode there is again an external entity pushing data 
//to your RPi, The way it pushes is when the data is ready it 
//triggers an interrupt by changing the logic state of any one 
//of the GPIO pin. The moment an interrupt is triggered you read 
//the logic state of four another pins and store the value to a 
//variable in your C program
#include<stdio.h>
#include<stdlib.h>
#include <wiringPi.h>
#define INTERRUPT_PIN 0//interrupt pin
#define OUT_PIN_1 1 //Read pin
#define OUT_PIN_2 2 //Read pin
#define OUT_PIN_3 3 //Read pin
#define OUT_PIN_4 4 //Read pin

void interrupt()
{
	int pin1=digitalRead(READ_PIN_1);
	int pin2=digitalRead(READ_PIN_2);
	int pin3=digitalRead(READ_PIN_3);
	int pin4=digitalRead(READ_PIN_4);

	printf("Value of Pin 1 is %d\n", pin1); //Print pin 1 value
	printf("Value of Pin 2 is %d\n", pin2); //Print pin 2 value
	printf("Value of Pin 3 is %d\n", pin3); //Print pin 3 value
	printf("Value of Pin 4 is %d\n",pin4); //Print pin 4 value
}
int main()
{
	wiringPiSetup(); //setup the library
	pinMode (INTERRUPT_PIN, INPUT);//setting input mode on pins
	pinMode (OUT_PIN_1, OUTPUT);
	pinMode (OUT_PIN_2, OUTPUT);
	pinMode (OUT_PIN_3, OUTPUT);
	pinMode (OUT_PIN_3, OUTPUT);
	//setting interrupt handlers

	wiringPiISR(INTERRUPT_PIN, INT_EDGE_BOTH, &interrupt)
	while(1)
	{
		printf("Waiting for interrupt\n");
	}
	return 0;
}