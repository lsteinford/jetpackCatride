#ifndef HEADER_H
#define HEADER_H

#include <iostream>
// #include <time.h>
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "Objects.h"
// #include "button.h"

const double frameRate = 30.0;
const double frameTime = 1.0 / frameRate;

const int WINDOW_SIZE_X = 1200;
const int WINDOW_SIZE_Y = 675;

const sf::IntRect playerRect(0, 0, 64, 48); // Sprite sheet size: 640x240
const sf::IntRect coinRect(0,0,9,9);
const sf::IntRect buttonRect(167, 310, 405, 150); // Sprite sheet size: 2000x5645

void mainMenu(bool& startGame, Game& game, Objects& Player, Objects& Background, Objects startButton, double deltaTime);
void gameRun(bool& startGame, bool& failedGame, Game& game, Objects& Background, Objects& Player, Objects& Obstacles, Objects& Coins, double deltaTime);
void deathScreen();


#endif