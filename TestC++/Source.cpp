#include <SFML/Graphics.hpp>
#include "Spaceship.h"
#include "Game.h"
#include <iostream>

int main()
{
	if (Bullet::bulletTexture.loadFromFile("laser.png") == false) {
		std::cout << "Erreur de chargement" << std::endl;
	};

	if (Enemy::enemyTexture.loadFromFile("enemy.png") == false) {
		std::cout << "Erreur de chargement" << std::endl;
	};

	Game game("game");
	game.run();
}