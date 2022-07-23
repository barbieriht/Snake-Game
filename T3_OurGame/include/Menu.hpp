#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

#define MAX_ITEMS 2

class Menu
{
    public:
        Menu(float width, float height);
        ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){
        return selectedItemIndex;
        }

    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text text[MAX_ITEMS];
};

#endif // MENU_H

