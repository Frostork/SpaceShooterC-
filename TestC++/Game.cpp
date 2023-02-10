#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include "Game.h"
#include <iostream>

Game::Game(const std::string& title) : window(sf::VideoMode(800, 600), "Space Shooter"), spaceship(350, 500)
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
	spaceship.Shoot();
}

void Game::update()
{
	background.Move();
	spaceship.update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		enemyList.push_back(Enemy(200, 200, -0.5f));
	}

	for (int i = 0; i < enemyList.size(); i++)
	{
		enemyList[i].Move();

		//if (enemyList[i].y <= 800) {
		//	enemyList.erase(enemyList.begin() + i);
		//	std::cout << "enemy destroyed" << std::endl;
		//}
	}
}

void Game::render()
{
	window.clear();
	background.Draw(window);
	spaceship.display(window);

	for (auto& enemy : enemyList)
	{
		enemy.Draw(window);
	}

	window.display();
}