#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include "Game.h"
#include <iostream>

Game::Game(const std::string& title) : window(sf::VideoMode(800, 600), "Space Shooter"), spaceship(350,500)
{
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();

		update();

		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	spaceship.Move();
}

void Game::update()
{
	background.Move();
	spaceship.update();
}

void Game::render()
{
	window.clear();
	background.Draw(window);
	spaceship.display(window);
	window.display();
}