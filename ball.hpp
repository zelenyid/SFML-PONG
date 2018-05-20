#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::Vector2f position;

    sf::RectangleShape ballShape;

    float xVelocity = .2f;
    float yVelocity = .2f;
public:
    Ball(float startX, float StartY);

    sf::FloatRect getPosition();

    sf::RectangleShape getShape();

    float getXVelocity();

    void reboundSides();

    void reboundBatOrTop();

    void hitBottom();

    void update(float time);
};

#endif