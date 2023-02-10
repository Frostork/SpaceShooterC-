#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
    Enemy(double _x, double _y, double _verticalSpeed);
    void Move();
    void Draw(sf::RenderWindow& window);
    void Initialize();
    float x;
    float y;
    int life;
    float horizontalSpeed;
    float verticalSpeed;

    static sf::Texture enemyTexture;
    sf::Sprite enemySprite;
    sf::Clock clock_shoot;
};