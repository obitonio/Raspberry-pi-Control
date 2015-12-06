#include "Network.h"

Network::Network()
{

}

Network::Network(sf::Texture textureSucceed, sf::Texture textureFailed, sf::Vector2f position)
{
	m_status = m_socket.connect(SERVER_IP, SERVER_PORT);
	
	if (m_status != sf::Socket::Done)
    {
        	m_labelTexture = textureFailed;
    }
    else
    {
        	m_labelTexture = textureSucceed;
    }
	
	m_labelSprite.setTexture(m_labelTexture);
	
	m_position = position;
	m_labelSprite.setPosition(m_position);
}

Network::Network(sf::String textureLinkSucceed, sf::String textureLinkFailed, sf::Vector2f position)
{
	m_status = m_socket.connect(SERVER_IP, SERVER_PORT);
	
	if (m_status != sf::Socket::Done)
    {
        	m_labelTexture.loadFromFile(textureLinkFailed);
    }
    else
    {
        	m_labelTexture.loadFromFile(textureLinkSucceed);
    }
	
	m_labelSprite.setTexture(m_labelTexture);
	
	m_position.x = WINDOW_X/2 - m_labelTexture.getSize().x/2;
	m_position.y = 150;
	m_labelSprite.setPosition(m_position);
}

void Network::send(int id)
{
	sf::Packet packet;
		
	int time = 1000;
	packet << id << time;


	m_socket.send(packet);
        
}

void Network::draw(sf::RenderTarget &target)
{
	target.draw(m_labelSprite);
}

Network::~Network()
{

}
