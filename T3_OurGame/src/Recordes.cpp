#include "Recordes.hpp"

Recordes::Recordes(int score, int highscore, float width, float height):score(score), highscore(highscore)
{
    if(!font.loadFromFile("SuperMario256.ttf"))
    {
    }
    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Game Over");
    text[0].setPosition(sf::Vector2f(width/2, height/(7)*1));

    text[1].setFont(font);
    text[1].setColor(sf::Color::Yellow);
    text[1].setString("Highscore");
    text[1].setPosition(sf::Vector2f(width/2, height/(7)*2));

    text[2].setFont(font);
    text[2].setColor(sf::Color::White);
    text[2].setString(std::to_string(highscore-4));
    text[2].setPosition(sf::Vector2f(width/2, height/(7)*3));

    text[3].setFont(font);
    text[3].setColor(sf::Color::Yellow);
    text[3].setString("Your score");
    text[3].setPosition(sf::Vector2f(width/2, height/(7)*4));

    text[4].setFont(font);
    text[4].setColor(sf::Color::White);
    text[4].setString(std::to_string(score-4));
    text[4].setPosition(sf::Vector2f(width/2, height/(7)*5));

    text[5].setFont(font);
    text[5].setColor(sf::Color::Red);
    text[5].setString("Quit");
    text[5].setPosition(sf::Vector2f(width/2, height/(7)*6));


}

Recordes::~Recordes()
{
}

void Recordes::draw(sf::RenderWindow &window)
{
         for(int i = 0; i < 6; i++)
     {
         window.draw(text[i]);
     }
}

int Recordes::getScore()
{
    return score;
}

int Recordes::getHighscore()
{
    return highscore;
}
