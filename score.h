#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Score
{
public:
    Score()
    {
        scoreTotal = 0;
        if (!scoreFont.loadFromFile("assets/college.ttf"))
        {
            std::cout<<"Error opening file\n";
            exit(2);
        }
        scoreText.setFont(scoreFont);
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10,10);
    }
    void increaseScore(int value)
        {scoreTotal += value;}
    int getScore() const 
        {return scoreTotal;}
    void update()
        {scoreText.setString("Score: " + std::to_string(scoreTotal));}
    void draw(sf::RenderWindow& window) 
        {window.draw(scoreText);}
private:
    int scoreTotal;

    sf::Text scoreText;
    sf::Font scoreFont;
};

#endif
