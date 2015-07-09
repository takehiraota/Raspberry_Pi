#include <stdio.h>
#include <wiringPi.h>
 
#define GPIO_2 2
#define GPIO_3 3
#define GPIO_4 4
#define GPIO_5 5
#define GPIO_6 6
#define GPIO_7 7
#define GPIO_8 8
#define GPIO_9 9

#define LED_0	0
#define LED_1	1
#define LED_2	2
#define LED_3	3
#define LED_NUM 4

#define DEBUG_PRINT 0

int initialize(void);
int finalize(void);
int decode(int num, int *led);

int main(void)
{
	int i = 0;
	int led[LED_NUM] = {0};

	if(initialize() == 1) return 1;

	for(i = 0; i <= 9; i++){
		decode(i, led);
		delay(1000);
		if(i == 9){
			i = 0;
		}

	}

	finalize();

	return 0;
}

int initialize(void)
{
	if(wiringPiSetupGpio() == -1){
		return 1;
	}else{
		pinMode(GPIO_2, OUTPUT);
		pinMode(GPIO_3, OUTPUT);
		pinMode(GPIO_4, OUTPUT);
		pinMode(GPIO_5, OUTPUT);
		pinMode(GPIO_6, OUTPUT);
		pinMode(GPIO_7, OUTPUT);
		pinMode(GPIO_8, OUTPUT);
		pinMode(GPIO_9, OUTPUT);
	}
	return 0;
}

int finalize(void)
{
    digitalWrite(GPIO_2, LOW);
    digitalWrite(GPIO_3, LOW);
    digitalWrite(GPIO_4, LOW);
    digitalWrite(GPIO_5, LOW);
    digitalWrite(GPIO_6, LOW);
    digitalWrite(GPIO_7, LOW);
    digitalWrite(GPIO_8, LOW);
    digitalWrite(GPIO_9, LOW);
	return 0;
}

int decode(int num, int *led)
{
	switch(num){
		case 0:
			digitalWrite(GPIO_2, HIGH);
			digitalWrite(GPIO_3, HIGH);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, LOW);
			digitalWrite(GPIO_7, HIGH);
			digitalWrite(GPIO_8, HIGH);
			digitalWrite(GPIO_9, HIGH);
			break;

		case 1:
			digitalWrite(GPIO_2, LOW);
			digitalWrite(GPIO_3, LOW);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, LOW);
			digitalWrite(GPIO_7, HIGH);
			digitalWrite(GPIO_8, LOW);
			digitalWrite(GPIO_9, LOW);
			break;

		case 2:
			digitalWrite(GPIO_2, HIGH);
			digitalWrite(GPIO_3, HIGH);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, LOW);
			digitalWrite(GPIO_6, HIGH);
			digitalWrite(GPIO_7, HIGH);
			digitalWrite(GPIO_8, LOW);
			digitalWrite(GPIO_9, HIGH);
			break;

		case 3:
			digitalWrite(GPIO_2, LOW);
			digitalWrite(GPIO_3, HIGH);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, HIGH);
			digitalWrite(GPIO_7, HIGH);
			digitalWrite(GPIO_8, LOW);
			digitalWrite(GPIO_9, HIGH);
			break;

		case 4:
			digitalWrite(GPIO_2, LOW);
			digitalWrite(GPIO_3, LOW);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, HIGH);
			digitalWrite(GPIO_7, HIGH);
			digitalWrite(GPIO_8, HIGH);
			digitalWrite(GPIO_9, LOW);
			break;

		case 5:
			digitalWrite(GPIO_2, LOW);
			digitalWrite(GPIO_3, HIGH);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, HIGH);
			digitalWrite(GPIO_7, LOW);
			digitalWrite(GPIO_8, HIGH);
			digitalWrite(GPIO_9, HIGH);
			break;

		case 6:
			digitalWrite(GPIO_2, HIGH);
			digitalWrite(GPIO_3, HIGH);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, HIGH);
			digitalWrite(GPIO_7, LOW);
			digitalWrite(GPIO_8, HIGH);
			digitalWrite(GPIO_9, HIGH);
			break;

		case 7:
			digitalWrite(GPIO_2, LOW);
			digitalWrite(GPIO_3, LOW);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, LOW);
			digitalWrite(GPIO_7, HIGH);
			digitalWrite(GPIO_8, HIGH);
			digitalWrite(GPIO_9, HIGH);
			break;

		case 8:
			digitalWrite(GPIO_2, HIGH);
			digitalWrite(GPIO_3, HIGH);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, HIGH);
			digitalWrite(GPIO_7, HIGH);
			digitalWrite(GPIO_8, HIGH);
			digitalWrite(GPIO_9, HIGH);
			break;

		case 9:
			digitalWrite(GPIO_2, LOW);
			digitalWrite(GPIO_3, HIGH);
			digitalWrite(GPIO_4, LOW);
			digitalWrite(GPIO_5, HIGH);
			digitalWrite(GPIO_6, HIGH);
			digitalWrite(GPIO_7, HIGH);
			digitalWrite(GPIO_8, HIGH);
			digitalWrite(GPIO_9, HIGH);
			break;

		default:
			break;
	}

	return 0;
}
/*
int display_led(int *led)
{
	digitalWrite(GPIO_2, led[LED_0]);
	digitalWrite(GPIO_3, led[LED_1]);
	digitalWrite(GPIO_4, led[LED_2]);
	digitalWrite(GPIO_17, led[LED_3]);

	return 0;
}
*/

