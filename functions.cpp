#include "header.h"

void mainMenu(bool& startGame, Game& game, Objects Player, Objects& Background, Objects startButton, double deltaTime)
{
    while(startGame == false)
    {
        game.events();
        game.clear();
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }
        game.drawSprite(Player.player);
        game.drawSprite(startButton.button);
        Player.animateSprite();
        Background.moveBackground(deltaTime, WINDOW_SIZE_X);
        startButton.updateButton(game.e, game.window);

        game.display();

        if(startButton.getButtonState() == clicked)
        {
            startGame = true;
        }
    }
}

void gameRun(bool& startGame, bool& failedGame)
{
    while(startGame == true && failedGame == false)
    {
        
    }
}

void deathScreen()
{

}