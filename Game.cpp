#include "Game.h"

Game::Game(int winSizeX, int winSizeY, std::string gameName)
{
    window.create(sf::VideoMode(winSizeX, winSizeY), gameName);
}

void Game::events()
{
    while(window.pollEvent(e))
    {
        if(e.type == e.Closed)
        {
            window.close();
            exit(0);
        }
    }
}

void Game::display()
{
    window.display();
}

bool Game::gameRunning()
{
    if(window.isOpen())
    {
        return true;
    }
    return false;
}

void Game::drawText(sf::Text& t)
{
    window.draw(t);   
}

void Game::drawRect(sf::RectangleShape& rect)
{
    window.draw(rect);
}

void Game::drawSprite(sf::Sprite sprite)
{
    window.draw(sprite);
}

void Game::drawCircle(sf::CircleShape& circ)
{
    window.draw(circ);
}

void Game::clear()
{
    window.clear();
}



