#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

enum objState{coin, player};
enum buttonState{normal, hovered, clicked};

class Objects
{
public:
    // Background Init
    void initBackground(int width, int height);
    void moveBackground(double dt, int width);
    // Player Init
    void initPlayer(std::string playerFile, sf::IntRect rect);
    void movePlayer(sf::RenderWindow &window);
    // Obstacle Init
    void initObstacles(std::string obstFile);
    void moveObstacles(sf::RenderWindow& window);
    // Coin Init
    void initCoins(std::string coinFile);
    void moveCoins(sf::RenderWindow& window);
    // Button Init
    void initButton(std::string s, std::string text, sf::IntRect rect, sf::Vector2f position, sf::Vector2f size, sf::Color color);
    virtual void drawButton(sf::RenderTarget& target,sf::RenderStates states) const;
    void updateButton(sf::Event& e, sf::RenderWindow& window);
    sf::Uint32 getButtonState(){return btnState;};
    sf::Uint32 getObjState(){return objState;};
    sf::Vector2f getPosition(){return buttonPos;};
    // Sprite Animation
    void animateSprite(Objects& object);

    sf::Sprite player, obst, coin, button;
    sf::Texture playerTexture, obsTexture, coinTexture;
    sf::IntRect playerRect, coinRect, buttonRect;
    sf::Uint32 objState, btnState;
    sf::Vector2f buttonPos;
    sf::Color buttonColor, textNormal, textHover;
    sf::Font font;
    sf::Text buttonText;

    int playerX, playerY, playerSizeX, playerSizeY;
    int obstSizeX, obstSizeY;
    int coinSize;

    sf::Clock clock;

    // Background Variables
    sf::RectangleShape background[5], backgroundDupe[5];
    sf::Texture backTexture[5];
    float backgroundX[5], backgroundDupeX[5];
    float speeds[5] = {2.0, 1.7, 1.4, 1.1, 0.8};

    // Button Variables
    sf::Texture normalButton, hoverButton, clickButton;

};

#endif