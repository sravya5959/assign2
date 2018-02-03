//In this mode what you need to is Select four GPIO pins in Rpi ,
//if one  of these or more than one, changes pin  state ie their 
//logic state changes from Zero to One or One to ZERO you need to
//read the logic state of all the pins and get the value into
//a variable in your C -program.You can assume that there is 
//an external entity (another board is sending async data to your 
//Pi)
#include<stdio.h>
#include<stdlib.h>
#include <wiringPi.h>
#define READ_PIN_1 1 //Read pin
#define READ_PIN_2 2 //Read pin
#define READ_PIN_3 3 //Read pin
#define READ_PIN_4 4 //Read pin

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
	pinMode (READ_PIN_1, INPUT);//setting input mode on pins
	pinMode (READ_PIN_2, INPUT);
	pinMode (READ_PIN_3, INPUT);
	pinMode (READ_PIN_4, INPUT);

	//setting interrupt handlers
	
	wiringPiISR(READ_PIN_1, INT_EDGE_BOTH, &interrupt)
	wiringPiISR(READ_PIN_2, INT_EDGE_BOTH, &interrupt)
	wiringPiISR(READ_PIN_3, INT_EDGE_BOTH, &interrupt)
	wiringPiISR(READ_PIN_4, INT_EDGE_BOTH, &interrupt)
	while(1)
	{
		printf("Waiting for interrupt\n");
	}

}