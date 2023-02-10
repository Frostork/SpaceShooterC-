#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(double _x, double _y);
	double x;
	double y;
	double speed = 0.13f;
	void Move();
	void Draw(sf::RenderWindow& window);
	static sf::Texture bulletTexture;

protected:
	sf::Sprite bulletSprite;
	sf::Clock clock_Bullet;
};

