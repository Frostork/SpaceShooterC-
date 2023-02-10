#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Background.h"
#include "Enemy.h"


class Game {
public:

	static const int WINDOW_WIDTH = 800;

	static const int WINDOW_HEIGHT = 600;

	Game(const std::string& title);

	void run();

	void processEvents();

	void update();

	void render();

protected:
	sf::RenderWindow window;
	Background background;
	Spaceship spaceship;
	std::vector<Enemy> enemyList;
};