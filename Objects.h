#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <cmath>

enum objState{coin, player};
enum buttonState{normal, hovered, clicked};

class Objects
{
public:
    // Background Init
    void initBackground(int width, int height);
    void moveBackground(double dt);
    // Player Init
    void initPlayer(std::string playerFile, sf::IntRect rect);
    void movePlayer(sf::RenderWindow &window, sf::Event event, bool isKeyPressed);
    // Obstacle Init
    void initObstacles(std::string obstFile);
    void moveObstacles(sf::RenderWindow& window);
    // Coin Init
    void initCoins(std::string coinFile);
    void moveCoins(sf::RenderWindow& window);
    // Button Init
    void initButton(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    virtual void drawButton(sf::RenderTarget& target,sf::RenderStates states) const;
    void updateButton(sf::Event& e, sf::RenderWindow& window);
    sf::Uint32 getButtonState(){return btnState;};
    sf::Uint32 getObjState(){return objState;};
    sf::Vector2f getPosition(){return buttonPos;};
    // Sprite Animation
    void animateSprite();

    sf::Sprite player, obst, coin, button;
    sf::RectangleShape background, background2;
    sf::Texture backTexture, playerTexture, obsTexture, coinTexture, buttonTexture;
    sf::IntRect playerRect, coinRect;
    sf::Uint32 objState, btnState;
    sf::Vector2f buttonPos;
    sf::Color buttonColor, textNormal, textHover;
    sf::Font font;
    sf::Text buttonText;

    int playerX, playerY, playerSizeX, playerSizeY;
    int obstSizeX, obstSizeY;
    int coinSize;

    sf::Clock clock;

    float backgroundX, backgroundX2;

};

#endif