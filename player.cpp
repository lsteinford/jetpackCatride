#include "player.h"
#include "objects.h"

Player::Player(std::string plAsset)
{
    
    if(!mTexture.loadFromFile(plAsset))
    exit(-1);
    mPlayer.setTexture(mTexture);
    sf::Vector2f setPos;
    setPos.x = 100;
    setPos.y = 100;
    mPlayer.setPosition(setPos);
    sf::Vector2f setSize;
    setSize.x = 3;
    setSize.y = 3;
    mPlayer.setScale(setSize);
    spriteRect = {0,0,64,48};
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
            spriteRect.top = 192;
        }
        else
        {
            mPlayer.move(moveDown);
            spriteRect.top = 144;
        }
        setTexture();
        window.draw(mPlayer);

}


/**
 * @brief Cylces through cat sprite sheet to give animation
 * 
 * @author Luke
 */
void Player::setTexture()
{
    if(clock.getElapsedTime().asSeconds() > 0.3f)
    {
        if(spriteRect.left == 128)
        {
            spriteRect.left = 0;
        } else {
            spriteRect.left += 64;
        }

        mPlayer.setTextureRect(spriteRect);
        clock.restart();
    }
}