#include "game.h"

GameObject::GameObject(){
    velocity = 1;
    frequency = 10;
    skinPath = "assets/doge.png";
    if(!skin.loadFromFile(skinPath))
        exit(-1);
   
    sprite.setTexture(skin);

    sprite.setPosition(100, 300);
}

GameObject::GameObject(std::string funcSkinPath){
    velocity = 1;
    frequency = 10;
    skinPath = funcSkinPath;
    if(!skin.loadFromFile(skinPath))
        exit(-1);
   
    sprite.setTexture(skin);

    sprite.setPosition(200, 300);
}

void GameObject::live(sf::RenderWindow &window){
    sf::Vector2f position = sprite.getPosition();
    std::cout << position.x << " " << position.y << std::endl;

    sprite.move(-1, 0);

    window.draw(sprite);
        
}
