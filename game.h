#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

class GameObject{
    public:
        int velocity; // how many positions the object moves every refresh 
        int frequency; // how many times the object appears in a minute 
        std::string skinPath;
        int hitboxL;
        int hitboxW;
        int hitboxR;
        bool isRound; // need to know if hitbox is circle or rect

        GameObject(); // default contructor
       
        // MAKE SURE OBJECT VARS ARE INITIALIZED BEFORE USING
        void move(sf::RenderWindow &window); // takes velo, freq, skin, hitbox, and makes a moving object

    private:
        sf::Clock life;
};

#endif
