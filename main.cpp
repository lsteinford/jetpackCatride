#include <SFML/Graphics.hpp>
#include "game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 600), "SFML works!");
    GameObject doge;
    doge.skinPath = "assets/doge.png";
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        doge.move(window);    
        window.display();
    }

    return 0;
}
