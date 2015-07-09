#include <stdio.h>
#include <wiringPi.h>
 
#define GPIO_2 2
#define GPIO_3 3
#define GPIO_4 4
#define GPIO_17 17

#define LED_0	0
#define LED_1	1
#define LED_2	2
#define LED_3	3
#define LED_NUM 4

#define DEBUG_PRINT 0

int initialize(void);
int finalize(void);
int display(void);
int display_led(int *led);
int decode(int num, int *led);

int main(void)
{
	int i = 0;
	int led[LED_NUM] = {0};

	if(initialize() == 1) return 1;

	for(i = 1; i <= 15; i++){
		decode(i, led);
		display_led(led);
		delay(1000);
		if(i==15){
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
		pinMode(GPIO_17, OUTPUT);
	}
	return 0;
}

int finalize(void)
{
    digitalWrite(GPIO_2, LOW);
    digitalWrite(GPIO_3, LOW);
    digitalWrite(GPIO_4, LOW);
    digitalWrite(GPIO_17, LOW);

	return 0;
}

int display(void)
{
	int i = 0;

	for(i=0; i<10; i++){
		digitalWrite(GPIO_17, LOW);
		delay(100);
		digitalWrite(GPIO_17, HIGH);
		delay(100);
    }

}

int decode(int num, int *led)
{
	int i = 0;

	for(i = 0; i < LED_NUM; i++)
	{
		led[i] = LOW;
	}

	for(i = 0; num > 0; i++)
	{
		led[i] = num % 2;
		num = num / 2;
	}

#if DEBUG_PRINT
	for(i = 0; i < 4; i++)
	{
		printf("led[%d] = %ld\n", i, led[i]);
	}
	printf("\n");
#endif

	return 0;
}

int display_led(int *led)
{
	digitalWrite(GPIO_2, led[LED_0]);
	digitalWrite(GPIO_3, led[LED_1]);
	digitalWrite(GPIO_4, led[LED_2]);
	digitalWrite(GPIO_17, led[LED_3]);

	return 0;
}