#include "Background.h"
#include <iostream>

Background::Background()
{
	if (backgroundTexture.loadFromFile("background.png") == false) {
		std::cout << "Erreur de chargement" << std::endl;
	};

	background1.setTexture(backgroundTexture);

	background2.setTexture(backgroundTexture);
	background2.setPosition(0, -(float)backgroundTexture.getSize().y);
}


void Background::Move()
{
	//sprites move
	background1.move(sf::Vector2f(0, 0.05f));
	if (background1.getPosition().y >= (float)backgroundTexture.getSize().y) {
		background1.setPosition(0, -(float)backgroundTexture.getSize().y);
	}
	background2.move(sf::Vector2f(0, 0.05f));
	if (background2.getPosition().y >= (float)backgroundTexture.getSize().y) {
		background2.setPosition(0, -(float)backgroundTexture.getSize().y);
	}
}

void Background::Draw(sf::RenderWindow& window)
{
	//sprites draw
	window.draw(background1);
	window.draw(background2);
}