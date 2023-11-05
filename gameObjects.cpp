#include "objects.h"

GameObject::GameObject(){
    //srand(time(NULL));
    velocity = 0.1;
    //frequency = 10;
    skinPath = "assets/doge.png";
    if(!skin.loadFromFile(skinPath))
        exit(-1);
   
    sprite.setTexture(skin);
    sprite.scale(0.5f, 0.5f);
    sprite.setPosition(900, 600);
}

GameObject::GameObject(std::string funcSkinPath, float scalex, float scaley){
    //srand(time(NULL));
    velocity = 0.1;
    //frequency = 10;
    skinPath = funcSkinPath;
    if(!skin.loadFromFile(skinPath))
        exit(-1);
   
    sprite.setTexture(skin);
    sprite.scale(scalex, scaley);
    sprite.setPosition(900, 600);
}

void GameObject::live(sf::RenderWindow &window){
    sf::Vector2f position = sprite.getPosition();
    
    if(position.x<0){
        srand(time(NULL));
        sf::Time time = sf::seconds(0.1f);

        sprite.setPosition(900, (rand() %901));
    }

    sprite.move((-1*velocity), 0);
        
    window.draw(sprite);
        
}
