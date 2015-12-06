#ifndef NETWORK_H
#define NETWORK_H

#include "../Main.h"

class Network
{
    public:
        Network();
		
		Network(sf::Texture textureSucceed, sf::Texture textureFailed, sf::Vector2f position);
		Network(sf::String textureLinkSucceed, sf::String textureLinkFailed, sf::Vector2f position);
		
		void send(int id);

        void draw(sf::RenderTarget &target);

        virtual ~Network();
    protected:
    private:
        sf::Vector2f m_position;

        sf::Texture m_labelTexture;
        sf::Sprite m_labelSprite;
		
		sf::TcpSocket m_socket;
		sf::Socket::Status m_status;
};

#endif // NETWORK_H
