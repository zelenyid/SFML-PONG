#include "bat.hpp"

Bat::Bat(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    batShape.setSize(sf::Vector2f(50, 5));
    batShape.setPosition(position);
}

sf::FloatRect Bat::getPosition()
{
    return batShape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
    return batShape;
}

void Bat::moveLeft(float time)
{  
    position.x -= batSpeed * time;
}

void Bat::moveRight(float time)
{
    position.x += batSpeed * time;
}

void Bat::update()
{
    batShape.setPosition(position);
}