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
        
        startButton.updateButton(game.e, game.window);

        game.display();

        if(startButton.getButtonState() == clicked)
        {
            startGame = true;
        }
    }
}

void gameRun(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects& Player, Objects& Obstacles, Objects& Coins, double deltaTime, int score, sf::Clock& clock, sf::Time& timeSinceLastUpdate)
{
    while(startGame == true && failedGame == false)
    {
        game.events();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TIME_PER_FRAME)
        {


            sf::Text scoreText;
            sf::Font scoreFont;

            scoreFont.loadFromFile("assets/Superdie.otf");
            scoreText.setFont(scoreFont);
            scoreText.setString("Score: " + std::to_string(score));
            scoreText.setScale(0.75f, 0.75f);
            scoreText.setFillColor(sf::Color::Black);
            scoreText.setPosition(1, 1);
            // game.clear();
            Background.moveBackground(deltaTime, WINDOW_SIZE_X);
            for(int i = 0; i < 5; i++)
            {
                game.drawRect(Background.background[i]);
                game.drawRect(Background.backgroundDupe[i]);
            }
            
            game.drawSprite(Coins.coin);
            game.drawSprite(Obstacles.obstSprite);
            game.drawText(scoreText);
            
            Obstacles.moveObstacles(game.window, deltaTime, WINDOW_SIZE_X, WINDOW_SIZE_Y);
            Coins.moveCoins(game.window, deltaTime, WINDOW_SIZE_X, WINDOW_SIZE_Y);
            game.drawSprite(Player.player);
            Player.animateSprite();
            Coins.animateSprite();
            
            
            Player.movePlayer(game.window, WINDOW_SIZE_Y);

            sf::FloatRect obstBounds = Obstacles.obstHitBox.getGlobalBounds();
            sf::FloatRect coinBounds = Coins.coin.getGlobalBounds();
            sf::FloatRect playerBounds = Player.player.getGlobalBounds();
            if (playerBounds.intersects(obstBounds) == true){
                failedGame = true;
            }
            if(playerBounds.intersects(coinBounds) == true){
                Coins.coinCollide(score, WINDOW_SIZE_X, WINDOW_SIZE_Y);
            }
            timeSinceLastUpdate -= TIME_PER_FRAME;
        game.display();

        }
    }
}

void deathScreen(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects startButton, double deltaTime)
{
    while(startGame == true && failedGame == true)
    {
        game.events();

        Background.moveBackground(deltaTime, WINDOW_SIZE_X);
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }

        game.display();
    }
}