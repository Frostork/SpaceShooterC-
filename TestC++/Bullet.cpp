#include "Bullet.h"
#include <iostream>

sf::Texture Bullet::bulletTexture;

Bullet::Bullet(double _x, double _y)
{
	x = _x;
	y = _y;

	bulletSprite.setPosition(x, y);
	bulletSprite.setTexture(bulletTexture);
}

void Bullet::Move()
{
	y -= speed;
	bulletSprite.setPosition(x, y);
}

void Bullet::Draw(sf::RenderWindow& window)
{
	//sprites draw
	window.draw(bulletSprite);
}