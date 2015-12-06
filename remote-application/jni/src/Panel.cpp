#include "Panel.h"

Panel::Panel()
:m_buttonDown("resource/down.png", "resource/down2.png", sf::Vector2f(WINDOW_X/2 - (IMG_SIZE/2), WINDOW_Y/1.3)),
m_buttonUp("resource/up.png", "resource/up2.png", sf::Vector2f(WINDOW_X/2 - (IMG_SIZE/2), WINDOW_Y/4)),
m_buttonRight("resource/right.png", "resource/right2.png", sf::Vector2f(WINDOW_X/2+ (IMG_SIZE/2), WINDOW_Y/2)),
m_buttonLeft("resource/left.png", "resource/left2.png", sf::Vector2f(WINDOW_X/2 - IMG_SIZE - (IMG_SIZE/2), WINDOW_Y/2))
{

}

void Panel::update(sf::RenderWindow &target)
{
    m_buttonDown.update(target);
    m_buttonUp.update(target);
    m_buttonLeft.update(target);
    m_buttonRight.update(target);
}

int Panel::getValue()
{
    if (m_buttonUp.isPressed())
    {
        return 1;
    }
    else if (m_buttonDown.isPressed())
    {
        return 2;
    }
    else if (m_buttonRight.isPressed())
    {
        return 3;
    }
    else if(m_buttonLeft.isPressed())
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

void Panel::draw(sf::RenderTarget &target)
{
    m_buttonDown.draw(target);
    m_buttonUp.draw(target);
    m_buttonLeft.draw(target);
    m_buttonRight.draw(target);
}

Panel::~Panel()
{
    //dtor
}
