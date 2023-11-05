#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

class GameObject{
    public:
        float velocity; 
        int frequency; 
        std::string skinPath;
        sf::Texture skin;
        sf::Sprite sprite;

        // IF YOU USE DEFAULT CONSTRUCTOR IT WILL DEFAULT TO DOGE OBJECT
        GameObject(); // default constructor
        GameObject(std::string funcSkinPath, float scalex, float scaley, sf::IntRect frame, int leftValue, int spriteWidth);  
        // MAKE SURE OBJECT VARS ARE INITIALIZED BEFORE USING
        void live(sf::RenderWindow &window); // controls the life of an obj 

        sf::IntRect spriteRect;
        void updateTexture();
        int maxLeft, frameWidth;

        clock_t lastTime;

};

#endif
