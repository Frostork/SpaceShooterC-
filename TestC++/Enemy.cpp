#include "Enemy.h"

sf::Texture Enemy::enemyTexture;

Enemy::Enemy(double _x, double _y, double _verticalSpeed)
{
    x = _x;
    y = _y;
    verticalSpeed = _verticalSpeed;
    enemySprite.setTexture(enemyTexture);
}

void Enemy::Move()
{
    y -= verticalSpeed;
   
    enemySprite.setPosition(x, y);
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(enemySprite);
}

void Enemy::Initialize()
{
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(x, y);
}