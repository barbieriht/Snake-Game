#ifndef RECORDES_H
#define RECORDES_H

#include <SFML/Graphics.hpp>

class Recordes
{
    public:
        Recordes(int score, int highscore, float width, float height);
        virtual ~Recordes();
        void draw(sf::RenderWindow &window);
        void setScore(int score);
        void setHighscore(int highscore);
        virtual int getScore();
        virtual int getHighscore();
    private:
        int score, highscore;
        sf::Font font;
        sf::Text text[6];
};

#endif // RECORDES_H

