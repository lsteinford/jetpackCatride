#include "Objects.h"

//  BACKGROUND FUNCTIONS
/**
 * @brief Initialize background images
 * 
 * @param width 
 * @param height 
 */
void Objects::initBackground(int width, int height)
{
    background.setOrigin(backgroundX, 0);
    background.setSize(sf::Vector2f(width, height));
    background2.setOrigin(backgroundX2, 0);
    background2.setSize(sf::Vector2f(width, height));
    backTexture.loadFromFile("assets/city1/1.png");
    background.setTexture(&backTexture);
    background2.setTexture(&backTexture);
}

/**
 * @brief Move background images
 * 
 */
void Objects::moveBackground()
{
    if(backgroundX == 0)
    {
        backgroundX = -1200;
        backgroundX2 = 0;
    }
    if(backgroundX2 == 0)
    {
        backgroundX = 0;
        backgroundX2 = -1200;
    }

    background.setOrigin(backgroundX, 0);
    background2.setOrigin(backgroundX2, 0);

    backgroundX += 0.25;
    backgroundX2 += 0.25;
    
}

// PLAYER FUNCTIONS
/**
 * @brief Initialize Player Object
 * 
 * @param playerFile 
 * @param rect 
 */
void Objects::initPlayer(std::string playerFile, sf::IntRect rect)
{
    playerTexture.loadFromFile(playerFile);
    player.setTexture(playerTexture);
    player.setPosition(sf::Vector2f(playerX, playerY));
    player.setScale(sf::Vector2f(playerSizeX, playerSizeY));
    playerRect = rect;
    objState = objState::player;
    lastTime = clock();
}

/**
 * @brief Move Player object
 * 
 * @param window 
 * @param event 
 * @param isKeyPressed 
 */
void Objects::movePlayer(sf::RenderWindow &window, sf::Event event, bool isKeyPressed)
{
    sf::Vector2f moveUp;
    moveUp.x = 0;
    moveUp.y = -0.1;
    sf::Vector2f moveDown;
    moveUp.x = 0;
    moveDown.y = 0.05;

    if (isKeyPressed==true)
    {
        
        player.move(moveUp);
        playerRect.top = 192;
    }
    else
    {
        player.move(moveDown);
        playerRect.top = 144;
    }
    animateSprite();
    window.draw(player);
}

// OBSTACLE FUNCTIONS
/**
 * @brief Initialize Obstacles object
 * 
 * @param obstFile 
 */
void Objects::initObstacles(std::string obstFile)
{
    obsTexture.loadFromFile(obstFile);
    obst.setTexture(obsTexture);
    obst.setScale(sf::Vector2f(obstSizeX, obstSizeY));
    obst.setPosition(000, 000);
}

/**
 * @brief Move Obstacles
 * 
 * @param window 
 */
void Objects::moveObstacles(sf::RenderWindow& window)
{
    sf::Vector2f position = obst.getPosition();
    
    if(position.x<0){
        srand(time(NULL));//might wanna do this @ constructor instead, resource hungry, but betters random #s
        sf::Time time = sf::seconds(0.1f);
        obst.setPosition(900, (rand() % 901));
    }
    window.draw(obst);
}

// COIN FUNCTIONS
/**
 * @brief Initialize Coins object
 * 
 * @param coinFile 
 */
void Objects::initCoins(std::string coinFile)
{
    coinTexture.loadFromFile(coinFile);
    coin.setTexture(coinTexture);
    coin.setScale(sf::Vector2f(coinSize, coinSize));
    coin.setPosition(000, 000);
    objState = objState::coin;
}

/**
 * @brief Move Coins
 * 
 * @param window 
 */
void Objects::moveCoins(sf::RenderWindow& window)
{
    sf::Vector2f position = coin.getPosition();
    
    if(position.x<0){
        srand(time(NULL));//might wanna do this @ constructor instead, resource hungry, but betters random #s
        sf::Time time = sf::seconds(0.1f);
        coin.setPosition(900, (rand() % 901));
    }
    window.draw(coin);
}

/**
 * @brief Animates sprites for coins and player
 * 
 */
void Objects::animateSprite()
{

    clock_t currentTime = clock();

    double elapsedTime = static_cast<double>(currentTime - lastTime) / CLOCKS_PER_SEC;

    switch(objState)
    {
        case objState::player:
        {
            if(elapsedTime > 0.08f)
        {
            if(playerRect.left == 138)
            {
                playerRect.left = 10;
            } else {
                playerRect.left += 64;
            }

            player.setTextureRect(playerRect);
            lastTime = currentTime;
        }
        }
        case objState::coin:
        {
            if(elapsedTime > 0.07f)
            {
                if(coinRect.left == 54)
                {
                    coinRect.left = 0;
                } else {
                    coinRect.left += 9;
                }

                coin.setTextureRect(coinRect);
                lastTime = currentTime;
            }
        }
    }
}

// BUTTON FUNCTIONS
/**
 * @brief Initialize Buttons
 * 
 * @param s 
 * @param position 
 * @param size 
 * @param color 
 */
void Objects::initButton(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    buttonTexture.loadFromFile(s);
    button.setTexture(buttonTexture);

    // temporary until final button is drawn. This will be used with the button.png from lab9 and is needed to rotate the button
    // to give the "pushed" look
    sf::Vector2u imageSize = buttonTexture.getSize();
    button.setOrigin(imageSize.x/2, imageSize.y/2);
    buttonPos = position;
    button.setPosition(buttonPos);

    //button color
    buttonColor = color;
    button.setColor(buttonColor);

    button.setScale(size);

    //Button Text
    font.loadFromFile("assets/college.ttf");
    buttonText.setFont(font);
    unsigned int fontSize = button.getGlobalBounds().height/2;
    buttonText.setCharacterSize(fontSize);

    buttonText.setString(s);
    //set origin of text to the middle
    buttonText.setOrigin(buttonText.getGlobalBounds().width/2, buttonText.getGlobalBounds().height/2);
    //set position to the middle of the button
    buttonText.setPosition(position.x, position.y-fontSize/4);
    //choose colors
    textNormal = sf::Color::Green;
    textHover = sf::Color::Red;
    buttonText.setFillColor(textNormal);

    btnState = buttonState::normal;
}

/**
 * @brief Draw Button
 * 
 * @param target 
 * @param states 
 */
void Objects::drawButton(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(button, states);
    target.draw(buttonText, states);
}

/**
 * @brief Detect if mouse is over button
 * 
 * @param e 
 * @param window 
 */
void Objects::updateButton(sf::Event& e, sf::RenderWindow& window)
{
    //Allow window to be expanded without breaking
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

    bool mouseInButton =    worldPos.x >= button.getPosition().x - button.getGlobalBounds().width/2
                            && worldPos.x <= button.getPosition().x + button.getGlobalBounds().width/2
                            && worldPos.y >= button.getPosition().y - button.getGlobalBounds().height/2
                            && worldPos.y <= button.getPosition().y + button.getGlobalBounds().height/2;
    if(e.type == sf::Event::MouseMoved)
    {
        if(mouseInButton)
        {
            btnState = buttonState::hovered;
        }
        else
        {
            btnState = buttonState::normal;
        }
    }
    if (e.type == sf::Event::MouseButtonPressed)
    {
        if(e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                btnState = buttonState::clicked;
            }
            else
            {
                btnState = buttonState::normal;
            }
        }
    }
    if (e.type == sf::Event::MouseButtonReleased)
    {
        if (e.mouseButton.button==sf::Mouse::Left)
        {
            if(mouseInButton)
            {
                btnState = buttonState::hovered;
            }
            else
            {
                btnState = buttonState::normal;
            }
        }
    }
    switch(btnState)
    {
        case buttonState::normal:
        {
            button.setRotation(0);
            buttonText.setFillColor(textNormal);
            break;
        }
        case buttonState::hovered:
        {
            button.setRotation(0);
            buttonText.setFillColor(textHover);
            break;
        }
        case buttonState::clicked:
        {
            button.setRotation(180);
            buttonText.setFillColor(textHover);
            break;
        }
    }
}