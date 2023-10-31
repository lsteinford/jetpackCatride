#include "player.h"

GameObject::GameObject(){
    velocity = 1;
    frequency = 10;
}

void GameObject::move(){
    sf::Texture skin;
    if(!skin.loadFromFile(skinPath))
        exit(-1);

    sf::Sprite sprite;
    sprite.setTexture(skin);

    window.draw(sprite);
}
