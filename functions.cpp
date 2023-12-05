#include "header.h"

void mainMenu(bool& startGame, Game& game, Objects& Player, Objects& Background, Objects startButton, sf::Time& dt, sf::Clock clock, int& score)
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

    score = 0;


    dt = clock.restart();
    while(startGame == false)
    {
        game.events();
        dt += clock.restart();
        while (dt >= TIME_PER_FRAME)
        {
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
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                game.window.close();
                exit(EXIT_SUCCESS);
            }
            dt -= TIME_PER_FRAME;
            game.display();
        }
    }
}

void gameRun(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects& Player, Objects& Obst, Objects& Coins, int& score, sf::Clock& clock, sf::Time& dt)
{
    // Obst.initObstacles("assets/doge.png", WINDOW_SIZE_X, WINDOW_SIZE_Y, -3);
    Player.initPlayer("assets/superCatAnimation.png", playerRect);

    sf::Text scoreText;
    sf::Font scoreFont;

    scoreFont.loadFromFile("assets/Superdie.otf");
    scoreText.setFont(scoreFont);
    scoreText.setScale(0.75f, 0.75f);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(1, 1);

    int speedSwitch = 500;
    int makeItHardToWin = 2000;
    Obst.velocity.x = -3;

    dt = clock.restart();
    while(startGame == true && failedGame == false)
    {
        game.events();
        dt += clock.restart();
        while (dt >= TIME_PER_FRAME)
        {
            game.clear();
            Background.moveBackground(WINDOW_SIZE_X);
            for(int i = 0; i < 5; i++)
            {
                game.drawRect(Background.background[i]);
                game.drawRect(Background.backgroundDupe[i]);
            }
            scoreText.setString("Score: " + std::to_string(score));
            game.drawText(scoreText);

            sf::FloatRect playerBounds = Player.player.getGlobalBounds();
            Coins.initCoins(WINDOW_SIZE_X, WINDOW_SIZE_Y);
            if(score==speedSwitch&&score<2500)
            {
                speedSwitch+=100;
                Player.moveUp.y-=0.5;
                Player.moveDown.y+=0.5;

            }
            if(score >= makeItHardToWin){
                Obst.velocity.x *= 1.3;
                makeItHardToWin += 500;
            } else if(score >= 1500) {
                Obst.initObstacles(bossDoge, WINDOW_SIZE_X, WINDOW_SIZE_Y, {-6,0});
            } else if(score >= 500) {
                Obst.initObstacles(roboDoge, WINDOW_SIZE_X, WINDOW_SIZE_Y, {-4,0});
            } else if(score < 500) {
                Obst.initObstacles(doge, WINDOW_SIZE_X, WINDOW_SIZE_Y, {-3,0});
            }

            Obst.updateObstacles(game.window, WINDOW_SIZE_X, WINDOW_SIZE_Y, playerBounds, failedGame);
            Coins.updateCoins(game.window, WINDOW_SIZE_X, WINDOW_SIZE_Y, score, playerBounds);
            Player.animateSprite();
    

            Player.movePlayer(game.window, WINDOW_SIZE_Y);
            
            if(failedGame){
                Coins.resetObjects();
                Obst.resetObjects();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                game.window.close();
                exit(EXIT_SUCCESS);
            }
            dt -= TIME_PER_FRAME;
            game.display();
        }
    }
}

void deathScreen(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects startButton, sf::Time dt, sf::Clock clock, int& scoreTotal)
{
    dt = clock.restart();
    while(startGame == true && failedGame == true)
    {
        game.events();
        dt += clock.restart();
        while (dt >= TIME_PER_FRAME)
        {
            sf::Text retry, esc, score;
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

            score.setFont(font);
            score.setString("Final Score: " + std::to_string(scoreTotal));
            score.setScale(1.0f, 1.0f);
            score.setFillColor(sf::Color::Black);
            sf::FloatRect scoreBox = esc.getLocalBounds();
            score.setOrigin(scoreBox.width / 2, scoreBox.height / 2);
            score.setPosition(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2);

            Background.moveBackground(WINDOW_SIZE_X);
            for(int i = 0; i < 5; i++)
            {
                game.drawRect(Background.background[i]);
                game.drawRect(Background.backgroundDupe[i]);
            }

            game.drawText(retry);
            game.drawText(esc);
            game.drawText(score);

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                startGame = false;
                failedGame = false;
                scoreTotal = 0;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                game.window.close();
                exit(EXIT_SUCCESS);
            }
            
            dt -= TIME_PER_FRAME;
            game.display();
        }
    }
}
