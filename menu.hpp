#ifndef MENU_HPP
#define MENU_HPP

#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu
{
private:
    sf::Texture menuBackground;
    sf::Font font;
    int width;
    int height;

    sf::SoundBuffer buf_sound;
    sf::Sound sound;
    sf::Music music;

    int menuNum = 0;
public:
    sf::Text menu1;
    sf::Text menu2;
    sf::Sprite menuBg;
    bool isMenu = true;

    Menu(int h, int w);
    void processMenu(sf::RenderWindow &window);
    bool drawMenu(sf::RenderWindow &window);
};

#endif