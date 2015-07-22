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
#define GPIO_10 10
#define GPIO_11 11
#define GPIO_12 12
#define GPIO_13 13


#define LED_0	0
#define LED_1	1
#define LED_2	2
#define LED_3	3
#define LED_NUM 4

#define INTERVAL 1000
#define CYCLE 1


#define DEBUG_PRINT 0

int initialize(void);
int finalize(void);
int decode(int num, int digit, int *led);

int main(void)
{
	int i,n,m = 0;
	int led[LED_NUM] = {0};

	if(initialize() == 1) return 1;

	for(i = 0; i <= 9; i++){
		m = 0;
		while(m <= INTERVAL / CYCLE){
			decode(i, n, led);
			delay(CYCLE);
			if(n == 3)
			{
				n = 0;
			}else{
				n++;
			}
			m++;
		}
//		delay(INTERVAL);
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
		pinMode(GPIO_10, OUTPUT);
		pinMode(GPIO_11, OUTPUT);
		pinMode(GPIO_12, OUTPUT);
		pinMode(GPIO_13, OUTPUT);
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
    digitalWrite(GPIO_10, LOW);
    digitalWrite(GPIO_11, LOW);
    digitalWrite(GPIO_12, LOW);
    digitalWrite(GPIO_13, LOW);
	return 0;
}

int decode(int num, int digit, int *led)
{

	switch(digit){
		case 0:
			digitalWrite(GPIO_10, LOW);
			digitalWrite(GPIO_11, HIGH);
			digitalWrite(GPIO_12, HIGH);
			digitalWrite(GPIO_13, HIGH);
			break;

		case 1:
			digitalWrite(GPIO_10, HIGH);
			digitalWrite(GPIO_11, LOW);
			digitalWrite(GPIO_12, HIGH);
			digitalWrite(GPIO_13, HIGH);
			break;

		case 2:
			digitalWrite(GPIO_10, HIGH);
			digitalWrite(GPIO_11, HIGH);
			digitalWrite(GPIO_12, LOW);
			digitalWrite(GPIO_13, HIGH);
			break;

		case 3:
			digitalWrite(GPIO_10, HIGH);
			digitalWrite(GPIO_11, HIGH);
			digitalWrite(GPIO_12, HIGH);
			digitalWrite(GPIO_13, LOW);
			break;

		default:
			digitalWrite(GPIO_10, LOW);
			digitalWrite(GPIO_11, LOW);
			digitalWrite(GPIO_12, LOW);
			digitalWrite(GPIO_13, LOW);
			break;
	}

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

