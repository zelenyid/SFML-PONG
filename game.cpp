#include "game.hpp"

const unsigned WINDOW_WIDTH = 800;
const unsigned WINDOW_HEIGHT = 600;
const sf::String TITLE = "PONG";

Game::Game():
    window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE)
{
    texture.loadFromFile("Media/images/BG.png");
    bg.setTexture(texture);

    // Load text 
    font.loadFromFile("Media/fonts/DS-DIGIT.TTF");

    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setColor(sf::Color::White);

    myMenu = new Menu(WINDOW_HEIGHT, WINDOW_WIDTH);
    bat = new Bat(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50);
    ball = new Ball(WINDOW_WIDTH / 2, 1);

    score = 0;
    lives = 3;
}

Game::~Game()
{
    delete myMenu;
    delete bat;
    delete ball;
}

void Game::run()
{
    sf::Clock clock;
    
    window.setVerticalSyncEnabled(true);

    // Main Loop
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 1000;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }
           
        window.clear();
    
        //Start menu
        if (myMenu->isMenu) 
        {
            myMenu->processMenu(window); 
            myMenu->drawMenu(window);
        } 
        else 
        {
            drawGame(*bat, *ball, window, score, lives, hud, time);
            displayGame(window, bg, *bat, *ball, hud);
        }
    
        window.display();
    }
}

void Game::drawGame(Bat &bat, Ball &ball, sf::RenderWindow &window, int &score, int &lives, sf::Text &hud, float time) 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (bat.getPosition().left > 0)
            bat.moveLeft(time);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (bat.getPosition().left + 50 < window.getSize().x)
            bat.moveRight(time);
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window.close();
    }

    // Output score and lives
    std::stringstream ss;
    ss << "Score:" << score << "    Lives:" << lives;
    hud.setString(ss.str());
    
    if (ball.getPosition().top > window.getSize().y)
    {
        ball.hitBottom();

        lives--;
    
        if (lives < 1)
        {
            score = 0;
            lives = 3;
        }
    }

    if (ball.getPosition().top < 0)
    {
        ball.reboundBatOrTop();

        score++;
    }

    if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > window.getSize().x)
    {
        ball.reboundSides();
    }

    if (ball.getPosition().intersects(bat.getPosition()))
    {
        ball.reboundBatOrTop();
    }

    ball.update(time);
    bat.update();
}

void Game::displayGame(sf::RenderWindow &window, sf::Sprite bg, Bat bat, Ball ball, sf::Text hud) 
{
    window.draw(bg);
    
    window.draw(bat.getShape());
    
    window.draw(ball.getShape());
    
    window.draw(hud);
}