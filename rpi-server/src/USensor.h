#ifndef USENSOR_H_INCLUDED
#define USENSOR_H_INCLUDED

#include "Main.h"

class USensor
{
	public:
		USensor();

		void init(int echo, int triger);
		float getRange();

		~USensor();
	protected:
	private:
		int m_echo;
		int m_triger;
};


#endif
