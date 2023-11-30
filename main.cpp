#include "header.h"

int main()
{
    Game game(WINDOW_SIZE_X, WINDOW_SIZE_Y, "SuperCat JoyGlide");

    Objects start;
    Objects Background;
    Objects Player;
    Objects Coin;
    Objects Obstacle;
    Objects startButton;
    
    int score = 0;

    bool startGame = false;
    bool failedGame = false;

    while(game.gameRunning())
    {
        sf::Clock clock; // starts the clock
        sf::Time deltaTime = sf::Time::Zero;

        game.events();

        deltaTime -= TIME_PER_FRAME;

        if(startGame == false)
        {
            mainMenu(startGame, game, Player, Background, startButton, deltaTime);
        }
        if(startGame == true && failedGame == false)
        {
            gameRun(startGame, failedGame, game, Background, Player, Obstacle, Coin, score, clock, deltaTime);
        }
        if(failedGame)
        {
            deathScreen(startGame, failedGame, game, Background, startButton);
        }
    }

    return 0;
}