#ifndef NETWORK_H
#define NETWORK_H

#include "Main.h"

class Network
{
	public:
		Network();

		void loop();

		virtual ~Network();
	protected:
	private:
			sf::TcpListener m_listener;
			sf::TcpSocket m_socket;

};

#endif
