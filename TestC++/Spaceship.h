#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Spaceship
{
public:
	double x;
	double y;
	double speed;
	double current_cooldown;
	void Move();
	void display(sf::RenderWindow& window);
	void Shoot();
	void collision();
	void update();
	Spaceship(double _x, double _y);

protected:
	sf::Texture SpaceshipTexture;
	sf::Sprite SpaceshipSprite;
	sf::Clock clock_ship;
	sf::Clock clock_shoot_cooldown;
	std::vector<Bullet> bulletList;
};