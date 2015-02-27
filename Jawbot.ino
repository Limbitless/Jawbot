/**
 * Jawbot.ino
 *
 * Josh Kaplan
 * jk@joshkaplan.org
 *
 * This is super inneficient, just meant to convey Sam's logic. 
 */


// emg pins
int left_jaw = A0;
int right_jaw = A1;

// servos
int left_motor = 5;
int right_motor = 6;

// data
int left_val = 0;
int right_val = 0;

void setup()
{
	// initialize emg inputs
	pinMode(left_jaw, INPUT);
	pinMode(right_jaw, INPUT);

	// initialize motor outputs
	pinMode(left_motor, OUTPUT);	
	pinMode(right_motor, OUTPUT);
}


void loop()
{
	left_val  = analogRead(left_jaw);
	right_val = analogRead(right_jaw);

	if (left_val == LOW && right_val == LOW)
	{
		// do nothing
	}

	if (left_val == HIGH && right_val == LOW)
	{
		// turn
		digitalWrite(left_motor, HIGH);
		digitalWrite(right_motor, LOW);
		
		// delay
		delayMicroseconds(1200);

		// stop
		digitalWrite(left_motor, LOW);
		digitalWrite(right_motor, LOW);
	}

	if (left_val == LOW && right_val == HIGH)
	{
		// turn
		digitalWrite(left_motor, LOW);
		digitalWrite(right_motor, HIGH);
		
		// delay
		delayMicroseconds(1200);

		// stop
		digitalWrite(left_motor, LOW);
		digitalWrite(right_motor, LOW);
	}
	
	if (left_val == HIGH && right_val == HIGH)
	{
		digitalWrite(left_motor, HIGH);
		digitalWrite(right_motor, HIGH);
		
		// delay
		delayMicroseconds(2100);

		// stop
		digitalWrite(left_motor, LOW);
		digitalWrite(right_motor, LOW);
	}

}