#include "menu.hpp"

Menu::Menu(int h, int w) 
{
    height = h;
    width = w;
    font.loadFromFile("Media/fonts/DS-DIGIT.TTF");
    
    this->menu1.setFont(font);
    this->menu1.setCharacterSize(75);
        
    this->menu2.setFont(font);
    this->menu2.setCharacterSize(75);
    
    this->menuBackground.loadFromFile("Media/images/bg_menu.jpg");
    
    menuBg.setTexture(menuBackground);

    buf_sound.loadFromFile("Media/sound/Sound.ogg");
    sound.setBuffer(buf_sound);
    music.openFromFile("Media/sound/Music.ogg");
    
    std::stringstream ss1;
    ss1 << "START";
    this->menu1.setString(ss1.str());
    menu1.setPosition(width / 2 - 125, height / 2 - 75);
    
    std::stringstream ss2;
    ss2 << "EXIT";
    this->menu2.setString(ss2.str()); 
    menu2.setPosition(width / 2 - 125, height / 2);   
}

void Menu::processMenu(sf::RenderWindow &window) 
{
    menuNum = 0;
 
    menu1.setColor(sf::Color::White);
    menu2.setColor(sf::Color::White);

    if (sf::IntRect(width / 2 - 125, height / 2 - 75, 250, 75).contains(sf::Mouse::getPosition(window)))
    {
        menu1.setColor(sf::Color::Blue);
        menuNum = 1;
    }

    if (sf::IntRect(width / 2 - 125, height / 2, 200, 75).contains(sf::Mouse::getPosition(window)))
    {
        menu2.setColor(sf::Color::Blue);
        menuNum = 2;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (menuNum == 1) { sound.play(); isMenu = false; music.play(); music.setLoop(true); }
        if (menuNum == 2) { window.close(); isMenu = false; }
    }
}

bool Menu::drawMenu(sf::RenderWindow &window) 
{
    window.draw(menuBg);
    window.draw(menu1);
    window.draw(menu2);
}