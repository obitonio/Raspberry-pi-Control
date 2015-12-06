#include <wiringPi.h>
#include <SFML/Network.hpp>
#include <iostream>
#include <cstdlib>

#define PORT 3000

#define PIN_RIGHT_FORWARD 5
#define PIN_RIGHT_BACK 4
#define PIN_LEFT_FORWARD 3
#define PIN_LEFT_BACK 2

#define SENSOR_1_ECHO 0
#define SENSOR_2_ECHO 1
#define SENSOR_1_TRIGER 7
#define SENSOR_2_TRIGER 7
