#include "ball.hpp"

Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    ballShape.setSize(sf::Vector2f(11, 11));
    ballShape.setPosition(position);
}

sf::FloatRect Ball::getPosition()
{
    return ballShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
    return ballShape;
}

float Ball::getXVelocity()
{
    return xVelocity;
}

void Ball::reboundSides()
{
    xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop()
{
    position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
    position.y = 1;
    position.x = 500;
}

void Ball::update(float time)
{
    position.y += yVelocity * time;
    position.x += xVelocity * time;

    ballShape.setPosition(position);
}