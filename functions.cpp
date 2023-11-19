#include "header.h"

void mainMenu(bool& startGame, Game& game, Objects& Player, Objects& Background, Objects startButton, double deltaTime)
{
    while(startGame == false)
    {
        
        game.clear();
        Background.moveBackground(deltaTime, WINDOW_SIZE_X);
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }
        game.drawSprite(Player.player);
        game.drawSprite(startButton.button);
        Player.animateSprite();
        Player.movePlayer(game.window);
        
        startButton.updateButton(game.e, game.window);

        game.events();

        game.display();

        if(startButton.getButtonState() == clicked)
        {
            startGame = true;
            // break;
        }
    }
}

void gameRun(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects& Player, Objects& Obstacles, Objects& Coins, double deltaTime)
{
    while(startGame == true && failedGame == false)
    {
        game.clear();
        Background.moveBackground(deltaTime, WINDOW_SIZE_X);
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }
        game.drawSprite(Player.player);
        game.drawSprite(Obstacles.obst);
        game.drawSprite(Coins.coin);
        Obstacles.moveObstacles(game.window);
        Coins.moveCoins(game.window);
        Player.animateSprite();
        
        
        Player.movePlayer(game.window);
        game.display();
        
        game.events();

    }
}

void deathScreen()
{

}