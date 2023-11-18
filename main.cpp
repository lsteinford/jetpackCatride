#include "header.h"

int main()
{
    Game game(WINDOW_SIZE_X, WINDOW_SIZE_Y, "Jetpack Catride");

    Objects start;
    Objects Background;
    Objects Player;
    Objects Coin;
    Objects Obstacle;
    Objects startButton;
    

    bool startGame = false;
    bool failedGame = false;

    Player.initPlayer("assets/superCatAnimation.png", playerRect);
    Obstacle.initObstacles("assets/villiandoge.png");
    Coin.initCoins("assets/goldcoin1.png");

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
        game.events();
        sf::Time gameTime = game.clock.restart();
        double deltaTime = gameTime.asSeconds();
        sf::Clock clock;
        sf::Time elapsed = clock.restart();
        if (elapsed.asMilliseconds() < 10) {
            sf::sleep(sf::milliseconds(10) - elapsed);
            elapsed = clock.restart();
        }

        if(startGame == false)
        {
            mainMenu(startGame, game, Player, Background, startButton, deltaTime);
        }
        if(startGame == true && failedGame == false)
        {
            gameRun(startGame, failedGame, game, Background, Player, Obstacle, Coin, deltaTime);
        }
        if(failedGame)
        {
            deathScreen();
        }

    }

    return 0;
}