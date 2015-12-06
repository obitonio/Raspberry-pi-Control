#ifndef PANEL_H
#define PANEL_H

#include "../Main.h"
#include "Button.h"

class Panel
{
    public:
        Panel();

        void update(sf::RenderWindow &target);

        int getValue();

        void draw(sf::RenderTarget &target);


        virtual ~Panel();
    protected:
    private:
        Button m_buttonUp;
        Button m_buttonDown;
        Button m_buttonLeft;
        Button m_buttonRight;
};

#endif // PANEL_H
