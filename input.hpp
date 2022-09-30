#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Input
{
    struct Button { bool up2, down2, up, down, escape; };
    public:
        Input();
        Button GetButton(void) const;
        void InputHandler(Event event, RenderWindow& window);
    private:
        Button button;
};

#endif