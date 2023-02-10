#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

class Spaceship
{
public:
    double x;
    double y;
    double speed;
    void Move();
    void display(sf::RenderWindow& window);
    void fire();
    void collision();
    void update();
    Spaceship(double _x, double _y);

protected:
    sf::Texture SpaceshipTexture;
    sf::Sprite SpaceshipSprite;
    sf::Clock clock_ship;
};