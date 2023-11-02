#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>

const int WINDOW_SIZEX = 900;
const int WINDOW_SIZEY = 900;



class Player
{
public:

    Player(std::string plAsset);
    //~Player();
    
    void handleInput(sf::RenderWindow &window, sf::Event event);
    
    //void update(sf::Event& e, sf::RenderWindow& window);
    //virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

private:
    int xPos,
        yPos;

    sf::Texture mTexture;
    sf::Sprite mPlayer;
    sf::Vector2f mIncrement;


};

int const xStart = 0;
int const yStart = 0;



#endif