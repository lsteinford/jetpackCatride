#include <SFML/Graphics.hpp>
#include "game.h"
#include "button.h"

const int WINDOW_SIZE_X = 900;
const int WINDOW_SIZE_Y = 900;

bool gameStarted = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "jetpackCatride");
    GameObject doge("assets/doge.png");
    
    Button start("Start",{WINDOW_SIZE_X / 2,WINDOW_SIZE_Y / 2}, {0.5, 0.5}, sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            start.update(event, window);

            if(start.getState() == clicked)
            {
                gameStarted = true;
            }   
        }
        
        window.clear();
        if(!gameStarted)
        {
            window.draw(start);
        } else {
            doge.live(window);
        }
        window.display();
    }

    return 0;
}
