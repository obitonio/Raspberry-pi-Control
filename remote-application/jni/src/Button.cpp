#include "Button.h"

Button::Button()
{
    //ctor
}

Button::Button(sf::Texture texture, sf::Texture textureFired, sf::Vector2f position)
{
    m_buttonTexture = texture;
    m_buttonSprite.setTexture(m_buttonTexture);
	
	m_buttonTextureFired = textureFired;

    m_position = position;
    m_buttonSprite.setPosition(m_position);
}

Button::Button(sf::String textureLink, sf::String textureLinkFired, sf::Vector2f position)
{
    m_buttonTexture.loadFromFile(textureLink);
    m_buttonSprite.setTexture(m_buttonTexture);
	
	m_buttonTextureFired.loadFromFile(textureLinkFired);

    m_position = position;
    m_buttonSprite.setPosition(m_position);
}

void Button::update(sf::RenderWindow &target)
{
    if (sf::Touch::getPosition(0, target).x > m_position.x && sf::Touch::getPosition(0, target).x < m_position.x + m_buttonTexture.getSize().x &&
        sf::Touch::getPosition(0, target).y > m_position.y && sf::Touch::getPosition(0, target).y < m_position.y + m_buttonTexture.getSize().y &&
        sf::Touch::isDown(0))
    {
        m_isPressed = true;
    }
    else
    {
         m_isPressed = false;
    }
	
	if (sf::Touch::getPosition(0, target).x > m_position.x && sf::Touch::getPosition(0, target).x < m_position.x + m_buttonTexture.getSize().x &&
        sf::Touch::getPosition(0, target).y > m_position.y && sf::Touch::getPosition(0, target).y < m_position.y + m_buttonTexture.getSize().y)
    {
		m_buttonSprite.setTexture(m_buttonTextureFired);
	}
	else
	{
		m_buttonSprite.setTexture(m_buttonTexture);
	}
}

int Button::isPressed()
{
    return m_isPressed;
}

void Button::draw(sf::RenderTarget &target)
{
    target.draw(m_buttonSprite);
}

Button::~Button()
{
    //dtor
}
