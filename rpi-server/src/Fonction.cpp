#include "Main.h"

void forward(int time)
{
	digitalWrite(PIN_RIGHT_FORWARD, HIGH);
	digitalWrite(PIN_LEFT_FORWARD, HIGH);
	delay(time);
	digitalWrite(PIN_RIGHT_FORWARD, LOW);
	digitalWrite(PIN_LEFT_FORWARD, LOW);

}
