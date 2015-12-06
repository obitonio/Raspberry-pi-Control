#include "USensor.h"

USensor::USensor()
: m_triger(0),
m_echo(0)
{

}

void USensor::init(int echo, int triger)
{
	m_echo = echo;
	m_triger = triger;
	pinMode(m_echo, INPUT);
	pinMode(m_triger, OUTPUT);
	digitalWrite(m_triger, LOW);
}

float USensor::getRange()
{
	//Send trig pulse
        digitalWrite(m_triger, HIGH);
        delayMicroseconds(20);
        digitalWrite(m_triger, LOW);

        //Wait for echo start
        while(digitalRead(m_echo) == LOW);

        //Wait for echo end

	long startTime = micros();
        sf::Clock clock;
	while(digitalRead(m_echo) == HIGH);
        long travelTime = micros() - startTime;
	float test = clock.getElapsedTime().asSeconds();

        //Get distance in cm
	//std::cout << "TravelTime: " << test << std::endl;
        float distance = test * 17000;

        return distance;
}

USensor::~USensor()
{


}
