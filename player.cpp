#include "player.h"
#include "objects.h"

Player::Player(std::string plAsset, sf::IntRect frameRect)
{
    
    if(!mTexture.loadFromFile(plAsset))
    exit(-1);
    mPlayer.setTexture(mTexture);
    sf::Vector2f setPos;
    setPos.x = 200;
    setPos.y = 200;
    mPlayer.setPosition(setPos);
    sf::Vector2f setSize;
    setSize.x = 3;
    setSize.y = 3;
    mPlayer.setScale(setSize);
    spriteRect = frameRect;
    lastTime = clock();
}



void Player::handleInput(sf::RenderWindow &window, sf::Event event, bool isKeyPressed)
{

        sf::Vector2f moveUp;
        moveUp.x = 0;
        moveUp.y = -0.1;
        sf::Vector2f moveDown;
        moveUp.x = 0;
        moveDown.y = 0.05;

        if (isKeyPressed==true)
        {
            
            mPlayer.move(moveUp);
            spriteRect.left = 9;
            spriteRect.top = 198;
            spriteRect.width = 47;
            spriteRect.height = 33;


        }
        else
        {
            mPlayer.move(moveDown);
            spriteRect.left = 10;
            spriteRect.top = 149;
            spriteRect.width = 47;
            spriteRect.height = 33;

        }
        updateTexture();
        window.draw(mPlayer);

}


/**
 * @brief Cylces through cat sprite sheet to give animation
 * 
 * @author Luke
 */
void Player::updateTexture()
{
    clock_t currenTime = clock();

    double elapsedTime = static_cast<double>(currenTime - lastTime) /CLOCKS_PER_SEC;

    if(elapsedTime > 0.08f)
    {
        if(spriteRect.left == 128)
        {
            spriteRect.left = 0;
        } else {
            spriteRect.left += 64;
        }

        mPlayer.setTextureRect(spriteRect);
        lastTime = currenTime;
    }
}

