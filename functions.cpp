#include "header.h"

void mainMenu(bool& startGame, Game& game, Objects& Player, Objects& Background, Objects startButton, double deltaTime)
{
    while(startGame == false)
    {
        game.events();
        sf::Text title;
        sf::Font font;
        font.loadFromFile("assets/Superdie.otf");
        title.setFont(font);
        title.setString("SuperCat JoyGlide");
        title.setScale(2.5f, 2.5f);
        title.setFillColor(sf::Color::Black);
        sf::FloatRect textBox = title.getLocalBounds();
        title.setOrigin(textBox.width / 2, textBox.height / 2);
        title.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 4);


        game.clear();
        Background.moveBackground(deltaTime, WINDOW_SIZE_X);
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }
        game.drawSprite(Player.player);
        game.drawSprite(startButton.button);
        game.drawText(title);
        Player.animateSprite();
        // Player.movePlayer(game.window);
        
        startButton.updateButton(game.e, game.window);

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
        game.events();
        // game.clear();
        Background.moveBackground(deltaTime, WINDOW_SIZE_X);
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }
        game.drawSprite(Player.player);
        game.drawSprite(Obstacles.obst);
        game.drawSprite(Coins.coin);
        Obstacles.moveObstacles(game.window, deltaTime, WINDOW_SIZE_X, WINDOW_SIZE_Y);
        Coins.moveCoins(game.window, deltaTime, WINDOW_SIZE_X, WINDOW_SIZE_Y);
        Player.animateSprite();
        Coins.animateSprite();
        
        game.display();
        Player.movePlayer(game.window);
        

    }
}

void deathScreen()
{

}