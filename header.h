#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "Objects.h"

const double frameRate = 60.0;
const double frameTime = 1.0 / frameRate;

const sf::Time TIME_PER_FRAME = sf::seconds(1.f/ 60.f);

const int WINDOW_SIZE_X = 1200;
const int WINDOW_SIZE_Y = 675;

const sf::IntRect playerRect(9, 4, 49, 36); // Sprite sheet size: 640x240
const sf::IntRect coinRect(0,0,9,9);
const sf::IntRect buttonRect(167, 310, 405, 150); // Sprite sheet size: 2000x5645
const sf::IntRect obstRect(0,0,222,222); // Sprite sheet size: 222x222;

void mainMenu(bool& startGame, Game& game, Objects& Player, Objects& Background, Objects startButton, double deltaTime);
void gameRun(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects& Player, Objects& Obstacles, Objects& Coins, double deltaTime, int score, sf::Clock& clock, sf::Time& timeSinceLastUpdate);
void deathScreen(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects startButton, double deltaTime);


#endif