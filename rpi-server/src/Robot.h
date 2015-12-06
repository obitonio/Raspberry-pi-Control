#ifndef ROBOT_H
#define ROBOT_H

#include "Main.h"

class Robot
{
	public:
		Robot();

		void reset();

		void forward(int time);
		void backward(int time);

		void turnRight(int time);
		void turnLeft(int time);

		virtual ~Robot();
	protected:
	private:
		int m_turnTime;
};

#endif
