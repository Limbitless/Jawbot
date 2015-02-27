/**
 * Jawbot.ino
 *
 * Josh Kaplan
 * jk@joshkaplan.org
 *
 * This is super inneficient, just meant to convey Sam's logic. 
 */

#include <Servo.h>

#define FORWARD 180
#define REVERSE 0
#define STOP 	90

// servos
int left_servo = 5;
int right_servo = 6;

Servo servo1;
Servo servo2;

// emg pins
int left_jaw = A0;
int right_jaw = A1;

// data
int left_val = 0;
int right_val = 0;

// emg thresholds
float threshold = 0; 
float threshold1 = threshold;
float threshold2 = threshold;

/**
 * setup runs once.
 */
void setup()
{
	// initialize emg inputs
	pinMode(left_jaw, INPUT);
	pinMode(right_jaw, INPUT);

	// attach servos
	servo1.attach(left_servo);
	servo2.attach(right_servo);
}

/**
 * Loop runs infinitely
 */
void loop()
{
	left_val  = analogRead(left_jaw);
	right_val = analogRead(right_jaw);

	// bite down left jaw only, user wants to turn left
	if (left_val > threshold1 && right_val < threshold2)
	{
		// turn left
		servo1.write(FORWARD);
		servo2.write(REVERSE);
		
		// delay
		delayMicroseconds(1200);

		// stop
		servo1.write(STOP);
		servo2.write(STOP);
	}

	// bite down on right jaw only, user want's to turn right
	else if (right_val > threshold2 && left_val < threshold2)
	{
		// turn
		servo1.write(REVERSE);
		servo2.write(FORWARD);
		
		// delay
		delayMicroseconds(1200);

		// stop
		servo1.write(STOP);
		servo2.write(STOP);
	}
	
	// bite both sides, user wants to go forward
	else if (left_val > threshold1 && right_val > threshold2)
	{
		servo1.write(FORWARD);
		servo2.write(FORWARD);
		
		// delay
		delayMicroseconds(2100);

		// stop
		servo1.write(STOP);
		servo2.write(STOP);
	}

	// not biting
	else
	{
		servo1.write(STOP);
		servo2.write(STOP);
	}
}