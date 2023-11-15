#include "header.h"

int main()
{
    Game game(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Jetpack Catride");

    Objects start;
    Objects Background;
    Objects Player;
    Objects Coin;
    Objects startButton;
    

    bool startGame = false;
    bool failedGame = false;

    Player.initPlayer("assets/superCatAnimation.png", playerRect);
    Background.initBackground(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    // Button initialization
    sf::Vector2f positionStart;
    positionStart.x = WINDOW_SIZE_X/2;
    positionStart.y = WINDOW_SIZE_Y/2;
    sf::Vector2f sizeStart;
    sizeStart.x = 0.5;
    sizeStart.y = 0.5;
    startButton.initButton("assets/button.png", "Start", positionStart, sizeStart, sf::Color::Red);



    while(game.gameRunning())
    {
        game.events();
        sf::Time gameTime = game.clock.restart();
        double deltaTime = gameTime.asSeconds();

        if(startGame == false)
        {
            mainMenu(startGame, game, Player, Background, startButton, deltaTime);
        }
        if(startGame == true && failedGame == false)
        {
            gameRun(startGame, failedGame);
        }
        if(failedGame)
        {
            deathScreen();
        }

    }

    return 0;
}