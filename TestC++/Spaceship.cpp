#include "Spaceship.h"
#include "Bullet.h"
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
	current_cooldown = clock_shoot_cooldown.getElapsedTime().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && current_cooldown >= 0.25f)
	{
		Bullet bullet(x + 43.5f, y - 40);
		bulletList.push_back(bullet);

		clock_shoot_cooldown.restart();

		std::cout << "Fire" << std::endl;
	}

	for (int i = 0; i < bulletList.size(); i++)
	{
		bulletList[i].Move();
		if (bulletList[i].y <= -50) {
			bulletList.erase(bulletList.begin() + i);
			std::cout << "bullet destroyed" << std::endl;
		}
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
