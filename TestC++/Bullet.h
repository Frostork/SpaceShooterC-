#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet();
	void Move();
	void Draw(sf::RenderWindow& window);

protected:
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	sf::Clock clock_Bullet;
};

