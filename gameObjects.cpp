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
    lastTime = clock();
    spriteRect = {0,0,0,0};
}

GameObject::GameObject(std::string funcSkinPath, float scalex, float scaley, sf::IntRect frame, int leftValue, int spriteWidth){
    //srand(time(NULL));
    velocity = 0.1;
    //frequency = 10;
    skinPath = funcSkinPath;
    if(!skin.loadFromFile(skinPath))
        exit(-1);
   
    sprite.setTexture(skin);
    sprite.scale(scalex, scaley);
    sprite.setPosition(900, 600);
    lastTime = clock();
    spriteRect = frame;
    maxLeft = leftValue;
    frameWidth = spriteWidth;
}

void GameObject::live(sf::RenderWindow &window){
    sf::Vector2f position = sprite.getPosition();
    
    if(position.x<0){
        srand(time(NULL));//might wanna do this @ constructor instead, resource hungry, but betters random #s
        sf::Time time = sf::seconds(0.1f);
        sprite.setPosition(900, (rand() % 901));
    }

    sprite.move((-1*velocity), 0);
        
    updateTexture();
    window.draw(sprite);
        
}

void GameObject::updateTexture()
{
    clock_t currentTime = clock();

    double elapsedTime = static_cast<double>(currentTime - lastTime) / CLOCKS_PER_SEC;

    if(elapsedTime > 0.07f)
    {
        if(spriteRect.left == maxLeft)
        {
            spriteRect.left = 0;
        } else {
            spriteRect.left += frameWidth;
        }

        sprite.setTextureRect(spriteRect);
        lastTime = currentTime;
    }
}
