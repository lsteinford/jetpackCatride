#include "game.h"

GameObject::GameObject(){
    velocity = 1;
    frequency = 10;
    life =  
}

void GameObject::move(sf::RenderWindow &window){
    std::time_t currentTime = std::time(0);

    // load sprite texture, if it doesnt work, exit
    sf::Texture skin;
    if(!skin.loadFromFile(skinPath))
        exit(-1);

    sf::Sprite sprite;
    sprite.setTexture(skin);
  
    if(std::difftime(currentTime, initTime)){
        sprite.setposition();
    }
        
    window.draw(sprite);
        
    }
}
