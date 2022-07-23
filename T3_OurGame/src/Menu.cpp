#include "Menu.hpp"

Menu::Menu(float width, float height)
{
    if(!font.loadFromFile("SuperMario256.ttf"))
    {

    }

    selectedItemIndex = 0;

    text[0].setFont(font);
    text[0].setColor(sf::Color::Red);
    text[0].setString("Play");
    text[0].setPosition(sf::Vector2f(width/2, height/(MAX_ITEMS+1)*1));


    text[1].setFont(font);
    text[1].setColor(sf::Color::Green);
    text[1].setString("Quit");
    text[1].setPosition(sf::Vector2f(width/2, height/(MAX_ITEMS+1)*2));
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
     for(int i = 0; i < MAX_ITEMS; i++)
     {
         window.draw(text[i]);
     }
}

void Menu::MoveUp()
{
    if(selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if(selectedItemIndex + 1 < MAX_ITEMS)
    {
        text[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color::Red);
    }
}
