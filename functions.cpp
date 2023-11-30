#include "header.h"

void mainMenu(bool& startGame, Game& game, Objects& Player, Objects& Background, Objects startButton, sf::Time& dt)
{
    Player.initPlayer("assets/superCatAnimation.png", playerRect);
    Background.initBackground(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    // Button initialization
    sf::Vector2f positionStart;
    positionStart.x = WINDOW_SIZE_X/2;
    positionStart.y = WINDOW_SIZE_Y/2;
    sf::Vector2f sizeStart;
    sizeStart.x = 10;
    sizeStart.y = 10;
    startButton.initButton("assets/Button.png", "Start", buttonRect, positionStart, sizeStart, sf::Color::Red);

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
        Background.moveBackground(WINDOW_SIZE_X);
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
        if(startButton.getButtonState() == clicked)
        {
            startGame = true;
        }
        game.display();
    }
}

void gameRun(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects& Player, Objects& Obstacles, Objects& Coins, int score, sf::Clock& clock, sf::Time& dt)
{
    Obstacles.initObstacles("assets/villiandoge.png", obstRect);
    Coins.initCoins("assets/goldcoin1.png", coinRect);
    Player.initPlayer("assets/superCatAnimation.png", playerRect);

    dt = clock.restart();
    while(startGame == true && failedGame == false)
    {
        game.events();
        dt += clock.restart();
        while (dt >= TIME_PER_FRAME)
        {


            sf::Text scoreText;
            sf::Font scoreFont;

            scoreFont.loadFromFile("assets/Superdie.otf");
            scoreText.setFont(scoreFont);
            scoreText.setString("Score: " + std::to_string(score));
            scoreText.setScale(0.75f, 0.75f);
            scoreText.setFillColor(sf::Color::Black);
            scoreText.setPosition(1, 1);
            game.clear();
            Background.moveBackground(WINDOW_SIZE_X);
            for(int i = 0; i < 5; i++)
            {
                game.drawRect(Background.background[i]);
                game.drawRect(Background.backgroundDupe[i]);
            }
            
            game.drawSprite(Coins.coin);
            game.drawSprite(Obstacles.obstSprite);
            game.drawText(scoreText);
            
            Obstacles.moveObstacles(game.window, WINDOW_SIZE_X, WINDOW_SIZE_Y);
            Coins.moveCoins(game.window, WINDOW_SIZE_X, WINDOW_SIZE_Y);
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
            dt -= TIME_PER_FRAME;
            game.display();
        }
    }
}

void deathScreen(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects startButton)
{
    while(startGame == true && failedGame == true)
    {
        game.events();
        
        sf::Text retry, esc;
        sf::Font font;

        font.loadFromFile("assets/Superdie.otf");
        retry.setFont(font);
        retry.setString("Press R to retry");
        retry.setScale(2.5f, 2.5f);
        retry.setFillColor(sf::Color::Black);
        sf::FloatRect retryBox = retry.getLocalBounds();
        retry.setOrigin(retryBox.width / 2, retryBox.height / 2);
        retry.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 4);

        esc.setFont(font);
        esc.setString("Press Esc to give up");
        esc.setScale(1.0f, 1.0f);
        esc.setFillColor(sf::Color::Black);
        sf::FloatRect escBox = esc.getLocalBounds();
        esc.setOrigin(escBox.width / 2, escBox.height / 2);
        esc.setPosition(WINDOW_SIZE_X / 2, 10);

        Background.moveBackground(WINDOW_SIZE_X);
        for(int i = 0; i < 5; i++)
        {
            game.drawRect(Background.background[i]);
            game.drawRect(Background.backgroundDupe[i]);
        }

        game.drawText(retry);
        game.drawText(esc);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            startGame = false;
            failedGame = false;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            game.window.close();
            break;
        }
        

        game.display();
    }
}