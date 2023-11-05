#include <SFML/Graphics.hpp>
#include "objects.h"
#include "button.h"
#include "player.h"
#include "score.h"

const int WINDOW_SIZE_X = 900;
const int WINDOW_SIZE_Y = 900;

const sf::IntRect coinRect(0,0,9,9);
const sf::IntRect dogeRect(0,0,240,240);

bool gameStarted = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "jetpackCatride");
    Player play("assets/superCatAnimation.png");

    GameObject doge("assets/doge.png", 0.5f, 0.5f, dogeRect, 0, 240);
    GameObject doge2("assets/doge.png", 0.5f, 0.5f, dogeRect, 0, 240);
    GameObject doge3("assets/doge.png", 0.5f, 0.5f, dogeRect, 0, 240);
    GameObject goldCoin("assets/goldcoin1.png", 4.0f, 4.0f, coinRect, 27, 9);
    
    sf::Vector2f positionStart;
    positionStart.x = WINDOW_SIZE_X/2;
    positionStart.y = WINDOW_SIZE_Y/2;
    sf::Vector2f sizeStart;
    sizeStart.x = 0.5;
    sizeStart.y = 0.5;
    Button start("Start", positionStart, sizeStart, sf::Color::Red);

    bool isKeyPressed = false;
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
                isKeyPressed = true;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
                isKeyPressed = false;
            }
        }
        
        window.clear();
        if(!gameStarted)
        {
            window.draw(start);
            
        } else {
            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(0, 900)),
                sf::Vertex(sf::Vector2f(900, 900))
            };

            sf::Vertex line2[] =
            {
                sf::Vertex(sf::Vector2f(900, 0)),
                sf::Vertex(sf::Vector2f(900, 900))
            };

            window.draw(line, 2, sf::Lines);
            window.draw(line2, 2, sf::Lines);

            goldCoin.live(window);
            doge.live(window);

            bool passedFirstWave = false; 
            bool passedSecondWave = false;
            if(score.scoreTotal>5000){
                if(passedFirstWave==false){
                    doge.velocity = 0.2;
                    doge2.velocity = 0.2;
                    passedFirstWave = true;
                }
                doge2.live(window);
            }
            if(score.scoreTotal>10000){
                if(passedSecondWave==false){
                    doge.velocity = 0.3;
                    doge2.velocity = 0.3;
                    doge3.velocity = 0.3;
                    passedSecondWave = true;
                }
                doge3.live(window);
            }
            play.handleInput(window, event, isKeyPressed);
            score.draw(window);
            score.update();

        }
        window.display();
    }

    return 0;
}
