#ifndef GAME_HPP
#define GAME_HPP

#include <sstream>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.hpp"
#include "ball.hpp"
#include "bat.hpp"

extern const unsigned WINDOW_WIDTH;
extern const unsigned WINDOW_HEIGHT;
extern const sf::String TITLE;

class Game
{
private:
    sf::RenderWindow window;

    sf::Texture texture;
    sf::Sprite bg;

    sf::Text hud;
    sf::Font font;

    int score;
    int lives;

    Menu *myMenu;
    Bat *bat;
    Ball *ball;
public:
    Game();
    ~Game();

    void run();
    int getScore() { return score; };
    void setScore(int newScore) { score = newScore; };
    void drawGame(Bat &bat, Ball &ball, sf::RenderWindow &window, int &score, int &lives, sf::Text &hud, float time);
    void displayGame(sf::RenderWindow &window, sf::Sprite bg, Bat bat, Ball ball, sf::Text hud);
};

#endif