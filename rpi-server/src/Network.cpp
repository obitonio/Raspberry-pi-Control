#include "Network.h"

Network::Network()
{

}

void Network::loop()
{
	if (m_listener.listen(PORT) == sf::Socket::Done)
		std::cout << "Listen on port " << PORT << std::endl;
	else
		std::cout << "Can't listen on port " << PORT << std::endl;

	if (m_listener.accept(m_socket) == sf::Socket::Done)
	{
		std::cout << "Client connected" << std::endl;
	}
	else
		std::cout << "Error" << std::endl;

}

Network::~Network()
{

}
