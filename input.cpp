#include "input.hpp"

Input::Input()
{
    button.up2 = button.down2 = button.up = button.down = button.escape = false;
}

Input::Button Input::GetButton(void) const
{
    return button;
}

void Input::InputHandler(sf::Event event, RenderWindow& window)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }

    if (event.type == Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case Keyboard::Escape:
            button.escape = true;
            break;
        case Keyboard::Up:
            button.up2 = true;
            break;
        case Keyboard::Down:
            button.down2 = true;
            break;
        case Keyboard::W:
            button.up = true;
            break;
        case Keyboard::S:
            button.down = true;
            break;
        default:
            break;
        }
    }
    if (event.type == Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case Keyboard::Escape:
            button.escape = false;
            break;
        case Keyboard::Up:
            button.up2 = false;
            break;
        case Keyboard::Down:
            button.down2 = false;
            break;
        case Keyboard::W:
            button.up = false;
            break;
        case Keyboard::S:
            button.down = false;
            break;
        default:
            break;
        }
    } 
}