#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>

class GameObject{
    public:
        int velocity; 
        int frequency; // how many times the object appears in a minute 
        std::string skinPath;
        sf::Texture skin;
        sf::Sprite sprite;

        // IF YOU USE DEFAULT CONSTRUCTOR IT WILL DEFAULT TO DOGE OBJECT
        GameObject(); // default constructor
        GameObject(std::string funcSkinPath);  
        // MAKE SURE OBJECT VARS ARE INITIALIZED BEFORE USING
        void live(sf::RenderWindow &window); // controls the life of an obj 

};

#endif
