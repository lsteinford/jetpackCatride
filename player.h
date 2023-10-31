#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>


class GameObject{
    public:
        int velocity; // how many positions the object moves every refresh 
        int frequency; // how many times the object appears in a minute 
        std::string skinPath;
        sf::RectangleShape rectHitbox;
        sf::CircleShape circHitbox;
        int hitboxL;
        int hitboxW;
        int hitboxR;
        bool isRound; // need to know if hitbox is circle or rect

        GameObject();
       
        // MAKE SURE OBJECT IS INITIALIZED BEFORE USING
        void move(); // takes velo, freq, skin, hitbox, and makes a moving object

    private:
};

#endif
