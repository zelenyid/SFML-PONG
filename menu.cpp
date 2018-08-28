#include "menu.hpp"

Menu::Menu(int h, int w) 
{
    height = h;
    width = w;
    font.loadFromFile("Media/fonts/DS-DIGIT.TTF");
    
    menu1.setFont(font);
    menu1.setCharacterSize(75);
        
    menu2.setFont(font);
    menu2.setCharacterSize(75);

    autor.setFont(font);
    autor.setCharacterSize(30);

    menuBackground.loadFromFile("Media/images/bg_menu.jpg");
    
    menuBg.setTexture(menuBackground);

    // Load sound
    buf_sound.loadFromFile("Media/sound/Sound.ogg");
    sound.setBuffer(buf_sound);
    music.openFromFile("Media/sound/Music.ogg");
    
    std::stringstream ss1;
    ss1 << "START";
    menu1.setString(ss1.str());
    menu1.setPosition(width / 2 - 125, height / 2 - 75);
    
    std::stringstream ss2;
    ss2 << "EXIT";
    menu2.setString(ss2.str()); 
    menu2.setPosition(width / 2 - 125, height / 2);   

    std::stringstream ss3;
    ss3 << "----------RULE----------\nMove right - RIGHT\nMove left - LEFT\nExit from game - ESCAPE\nStudent group of KM-73\nDmytro Zeleniy";
    autor.setString(ss3.str()); 
    autor.setPosition(width - 310, height - 200);
}

void Menu::processMenu(sf::RenderWindow &window) 
{
    menuNum = 0;
 
    menu1.setColor(sf::Color::White);
    menu2.setColor(sf::Color::White);
    autor.setColor(sf::Color::Green);

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
    window.draw(autor);
}