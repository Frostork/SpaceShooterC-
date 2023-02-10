#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
	if (bulletTexture.loadFromFile("laser.png") == false) {
		std::cout << "Erreur de chargement" << std::endl;
	};

	bulletSprite.setTexture(bulletTexture);
}

void Bullet::Move()
{
	//sprites move
	bulletSprite.move(sf::Vector2f(0, -0.1f));
	if (bulletSprite.getPosition().y >= (float)bulletTexture.getSize().y) {
		bulletSprite.setPosition(0, -(float)bulletTexture.getSize().y);
	}
}

void Bullet::Draw(sf::RenderWindow& window)
{
	//sprites draw
	window.draw(bulletSprite);
}