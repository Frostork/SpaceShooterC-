#pragma once
#include <SFML/Graphics.hpp>

class Background
{
public:
	Background();
	void Move();
	void Draw(sf::RenderWindow& window);

protected:
	sf::Texture backgroundTexture;
	sf::Sprite background1, background2;
	sf::Clock clock_background;
};

