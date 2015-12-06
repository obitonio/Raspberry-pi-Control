#include "Robot.h"

Robot::Robot()
: m_turnTime(3000)
{
	pinMode(PIN_RIGHT_FORWARD, OUTPUT);
        pinMode(PIN_RIGHT_BACK, OUTPUT);
        pinMode(PIN_LEFT_FORWARD, OUTPUT);
        pinMode(PIN_LEFT_BACK, OUTPUT);

}

void Robot::reset()
{
	digitalWrite(PIN_RIGHT_FORWARD, LOW);
	digitalWrite(PIN_RIGHT_BACK, LOW);
	digitalWrite(PIN_LEFT_FORWARD, LOW);
	digitalWrite(PIN_LEFT_BACK, LOW);
}

void Robot::forward(int time)
{
	digitalWrite(PIN_RIGHT_FORWARD, HIGH);
	digitalWrite(PIN_LEFT_FORWARD, HIGH);

	delay(time);

	digitalWrite(PIN_RIGHT_FORWARD, LOW);
	digitalWrite(PIN_LEFT_FORWARD, LOW);
}

void Robot::backward(int time)
{
	digitalWrite(PIN_RIGHT_BACK, HIGH);
        digitalWrite(PIN_LEFT_BACK, HIGH);

        delay(time);

        digitalWrite(PIN_RIGHT_BACK, LOW);
        digitalWrite(PIN_LEFT_BACK, LOW);


}

void Robot::turnRight(int time)
{
	digitalWrite(PIN_RIGHT_BACK, HIGH);
        digitalWrite(PIN_LEFT_FORWARD, HIGH);

        delay(time);

        digitalWrite(PIN_RIGHT_BACK, LOW);
        digitalWrite(PIN_LEFT_FORWARD, LOW);

}

void Robot::turnLeft(int time)
{
        digitalWrite(PIN_RIGHT_FORWARD, HIGH);
        digitalWrite(PIN_LEFT_BACK, HIGH);

        delay(time);

        digitalWrite(PIN_RIGHT_FORWARD, LOW);
        digitalWrite(PIN_LEFT_BACK, LOW);

}

Robot::~Robot()
{
	this->reset();
}
