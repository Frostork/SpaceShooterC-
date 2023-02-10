#include "Spaceship.h"
#include <iostream>
#include <Windows.h>

Spaceship::Spaceship(double _x, double _y) : x(_x), y(_y)
{
	if (SpaceshipTexture.loadFromFile("spaceship.png") == false) {
		std::cout << "Erreur de chargement" << std::endl;
	};

	SpaceshipSprite.setTexture(SpaceshipTexture);
	speed = 350;
}

void Spaceship::Move()
{
	auto time_elapsed = clock_ship.getElapsedTime().asSeconds();
	clock_ship.restart();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && x > 0) {
		x -= speed * time_elapsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && x < 700) {
		x += speed * time_elapsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && y > 0) {
		y -= speed * time_elapsed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && y < 520) {
		y += speed * time_elapsed;
	}
}

void Spaceship::Shoot()
{
	current_cooldown -= clock_shoot_cooldown.getElapsedTime().asSeconds();
	clock_shoot_cooldown.restart();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && y < 520) {
		bulletList.push_back(Bullet());
	}
}

void Spaceship::display(sf::RenderWindow& window)
{
	window.draw(SpaceshipSprite);
	for (auto& bullet : bulletList)
	{
		bullet.Draw(window);
	}

	//Debug Player Position
	//std::cout << "Spaceship at position (" << this->x << "," << this->y << ")" << std::endl;
}


void Spaceship::collision()
{
	std::cout << "Collision" << std::endl;
}

void Spaceship::update()
{
	SpaceshipSprite.setPosition(x, y);
}
