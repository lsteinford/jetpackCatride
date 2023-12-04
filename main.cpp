#include "header.h"
#include <SFML/Audio.hpp>

int main()
{
    Game game(WINDOW_SIZE_X, WINDOW_SIZE_Y, "SuperCat JoyGlide");

    Objects start;
    Objects Background;
    Objects Player;
    Objects Coin("assets/goldcoin1.png", coinRect, WINDOW_SIZE_X, WINDOW_SIZE_Y);
    Objects Obst(WINDOW_SIZE_X, WINDOW_SIZE_Y, "assets/doge.png");
    Objects startButton;
    
    int score = 0;

    bool startGame = false;
    bool failedGame = false;
    sf::Time deltaTime = sf::Time::Zero;

    while(game.gameRunning())
    {   
        sf::Clock clock; // starts the clock
        sf::Music music; // doesnt start the clock

        music.openFromFile("assets/jetpackjoyridethemeSorryWeStoleThis.wav");
        music.setLoop(true);
        music.play();
        

        game.events();

        deltaTime = clock.restart();

        if(startGame == false)
        {
            mainMenu(startGame, game, Player, Background, startButton, deltaTime, clock);
        }
        if(startGame == true && failedGame == false)
        {
            deltaTime += clock.restart();
            gameRun(startGame, failedGame, game, Background, Player, Obst, Coin, score, clock, deltaTime);
        }
        if(failedGame)
        {
            deathScreen(startGame, failedGame, game, Background, startButton, deltaTime, clock);
        }
    }

    return 0;
}
