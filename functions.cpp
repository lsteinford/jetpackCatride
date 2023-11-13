#include "header.h"

void mainMenu(bool& startGame, Game& game, Objects Player, Objects& Background, Objects startButton)
{
    while(startGame == false)
    {
        game.clear();
        game.drawRect(Background.background);
        game.drawRect(Background.background2);
        game.drawSprite(Player.player);
        game.drawSprite(startButton.button);
        startButton.updateButton(game.e, game.window);
        Player.animateSprite();
        Background.moveBackground();

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