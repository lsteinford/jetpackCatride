#include <SFML/Graphics.hpp>
#include "player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 600), "SFML works!");
    GameObject doge;
    doge.skinPath = "assets/doge.png";
    
    sf::CircleShape shape1(100.f);
    sf::CircleShape shape2(100.f);
    sf::CircleShape shape3(100.f);
    shape2.setPosition(0,200);
    shape3.setPosition(0,400);
    int s1c[4] = {255, 0, 0, 255};
    int s2c[4] = {0, 255, 0, 255};
    int s3c[4] = {0, 0, 255, 255};
    int s1 = 0;
    int s2 = 1;
    int s3 = 2;
    int change[3][4] = {{s1c[0], s1c[1], s1c[2], s1c[3]}, {s2c[0],s2c[1],s2c[2],s2c[3]}, {s3c[0],s3c[1],s3c[2],s3c[3]}};
    shape1.setFillColor(sf::Color(s1c[0], s1c[1], s1c[2], s1c[3]));
    shape2.setFillColor(sf::Color(s2c[0],s2c[1],s2c[2],s2c[3]));
    shape3.setFillColor(sf::Color(s3c[0],s3c[1],s3c[2],s3c[3]));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }/*
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.y <= 200)
                {
                        if(s1<2){s1++;}
                        else 
                        {s1=0;}
                        shape1.setFillColor(sf::Color(change[s1][0],change[s1][1],change[s1][2],change[s1][3]));
                }
                else if(event.mouseButton.y <= 400)
                {
                        if(s2<2){s2++;}
                        else 
                        {s2=0;}
                        shape2.setFillColor(sf::Color(change[s2][0],change[s2][1],change[s2][2],change[s2][3]));
                }
                else if(event.mouseButton.y <= 600)
                {
                        if(s3<2){s3++;}
                        else 
                        {s3=0;}
                        shape3.setFillColor(sf::Color(change[s3][0],change[s3][1],change[s3][2],change[s3][3]));
                }

            }*/

        }

        window.clear();
        doge.move();    
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();
    }

    return 0;
}
