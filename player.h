#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <time.h>
#include <iostream>

const int WINDOW_SIZEX = 900;
const int WINDOW_SIZEY = 900;



class Player
{
public:

    Player(std::string plAsset, sf::IntRect frameRect);
    //~Player();
    
    void handleInput(sf::RenderWindow &window, sf::Event event, bool isKeyPressed);
    
    //void update(sf::Event& e, sf::RenderWindow& window);
    //virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;
    
    void updateTexture();

    int xPos,
        yPos;

    sf::Texture mTexture;
    sf::Sprite mPlayer;
    sf::Vector2f mIncrement;
    sf::Keyboard mKeyboard;
    sf::IntRect spriteRect;
    clock_t lastTime;

};

int const xStart = 0;
int const yStart = 0;



#endif