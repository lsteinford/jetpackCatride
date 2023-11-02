#include <SFML/Graphics.hpp>
#include "game.h"
#include "button.h"
#include "player.h"
#include "score.h"

const int WINDOW_SIZE_X = 900;
const int WINDOW_SIZE_Y = 900;

bool gameStarted = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "jetpackCatride");
    GameObject doge("assets/doge.png");
    Player play("assets/cat.png");
    
    sf::Vector2f positionStart;
    positionStart.x = WINDOW_SIZE_X/2;
    positionStart.y = WINDOW_SIZE_Y/2;
    sf::Vector2f sizeStart;
    sizeStart.x = 0.5;
    sizeStart.y = 0.5;
    Button start("Start", positionStart, sizeStart, sf::Color::Red);

    Score score;

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

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                score.increaseScore(100);
                score.update();
            }
        }
        
        window.clear();
        if(!gameStarted)
        {
            window.draw(start);
            
        } else {
            doge.live(window);
            play.handleInput(window, event);
            score.draw(window);
            score.update();

        }
        window.display();
        
    }

    return 0;
}
