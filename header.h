#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "Objects.h"

const sf::Time TIME_PER_FRAME = sf::seconds(1.f/ 60.f);

const int WINDOW_SIZE_X = 1200;
const int WINDOW_SIZE_Y = 675;


const sf::IntRect playerRect(9, 4, 49, 36); // Sprite sheet size: 640x240
const sf::IntRect coinRect(0,0,9,9);
const sf::IntRect buttonRect(167, 310, 405, 150); // Sprite sheet size: 2000x5645
const sf::IntRect obstRect(0,0,222,222); // Sprite sheet size: 222x222;

const std::string doge = "assets/doge.png";
const std::string roboDoge = "assets/villiandoge.png";
const std::string bossDoge = "assets/finalvilliandoge.png";

void mainMenu(bool& startGame, Game& game, Objects& Player, Objects& Background, Objects startButton, sf::Time& dt, sf::Clock clock);
void gameRun(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects& Player, Objects& obstacleOne, Objects& Coins, int& score, sf::Clock& clock, sf::Time& dt);
void deathScreen(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects startButton, sf::Time dt, sf::Clock clock, int& scoreTotal);


#endif
