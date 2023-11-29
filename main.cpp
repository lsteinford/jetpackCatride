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

    Player.initPlayer("assets/superCatAnimation.png", playerRect);
    Obstacle.initObstacles("assets/villiandoge.png", obstRect);
    Coin.initCoins("assets/goldcoin1.png", coinRect);

    Background.initBackground(WINDOW_SIZE_X, WINDOW_SIZE_Y);

    // Button initialization
    sf::Vector2f positionStart;
    positionStart.x = WINDOW_SIZE_X/2;
    positionStart.y = WINDOW_SIZE_Y/2;
    sf::Vector2f sizeStart;
    sizeStart.x = 10;
    sizeStart.y = 10;
    startButton.initButton("assets/Button.png", "Start", buttonRect, positionStart, sizeStart, sf::Color::Red);

    while(game.gameRunning())
    {
        sf::Clock clock; // starts the clock
        sf::Time timeSinceLastUpdate = sf::Time::Zero;

        game.events();

        double deltaTime = frameTime;
        timeSinceLastUpdate -= TIME_PER_FRAME;

        if(startGame == false)
        {
            mainMenu(startGame, game, Player, Background, startButton, deltaTime);
        }
        if(startGame == true && failedGame == false)
        {
            gameRun(startGame, failedGame, game, Background, Player, Obstacle, Coin, deltaTime, score, clock, timeSinceLastUpdate);
        }
        if(failedGame)
        {
            deathScreen(startGame, failedGame, game, Background, startButton, deltaTime);
        }
    }

    return 0;
}