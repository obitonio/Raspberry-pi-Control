#ifndef BUTTON_H
#define BUTTON_H

#include "../Main.h"

class Button
{
    public:
        Button();

        Button(sf::Texture texture, sf::Texture textureFired, sf::Vector2f position);
        Button(sf::String textureLink, sf::String textureLinkFired, sf::Vector2f position);

        void update(sf::RenderWindow &target);

        int isPressed();

        void draw(sf::RenderTarget &target);

        virtual ~Button();
    protected:
    private:
        bool m_isPressed;

        sf::Vector2f m_position;

        sf::Texture m_buttonTexture, m_buttonTextureFired;
        sf::Sprite m_buttonSprite;
};

#endif // BUTTON_H
