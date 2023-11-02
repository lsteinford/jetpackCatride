#include "player.h"
#include "game.h"

Player::Player(std::string plAsset)
{
    
    if(!mTexture.loadFromFile(plAsset))
    exit(-1);
    mPlayer.setTexture(mTexture);
    sf::Vector2f setPos;
    setPos.x = 500;
    setPos.y = 100;
    mPlayer.setPosition(setPos);
    sf::Vector2f setSize;
    setSize.x = 0.5;
    setSize.y = 0.5;
    mPlayer.setScale(setSize);
}



void Player::handleInput(sf::RenderWindow &window, sf::Event event)
{

        sf::Vector2f moveUp;
        moveUp.x = 0;
        moveUp.y = -0.1;
        sf::Vector2f moveDown;
        moveUp.x = 0;
        moveDown.y = 0.01;

        if (event.type == sf::Event::MouseButtonPressed)
        {
            mPlayer.move(moveUp);
        }
        else
        {
            mPlayer.move(moveDown);
        }
        window.draw(mPlayer);

}