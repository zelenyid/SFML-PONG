#ifndef BAT_HPP
#define BAT_HPP

#include <SFML/Graphics.hpp>

// Class of platform
class Bat 
{
private:
    sf::Vector2f position;

    sf::RectangleShape batShape;

    float batSpeed = .3f;
public:
    Bat(float startX, float startY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    void moveLeft(float time);

    void moveRight(float time);

    void update();
};

#endif