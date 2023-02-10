/**
* @class Game
* @brief Represents a game
* @details Contains information about the game window size and functions necessary to run the game
,→ (event handling, updating, rendering)
* @author Lucien Mousin
*/
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Background.h"


class Game {
public:
	/**
	* @brief Width of the game window
	*/
	static const int WINDOW_WIDTH = 800;
	/**
	* @brief Height of the game window
	*/
	static const int WINDOW_HEIGHT = 600;
	/**
	* @brief Constructor for the Game class
	* @param title Title of the game window
	*/
	Game(const std::string& title);
	/**
	* @brief Runs the game
	* @details Main game loop that handles events, updates, and rendering
	*/
	void run();
	/**
	* @brief Processes events for the game window
	*/
	void processEvents();
	/**
	* @brief Updates the state of the game
	*/
	void update();
	/**
	* @brief Renders the game on the screen
	*/
	void render();
protected:
	sf::RenderWindow window; /**< SFML render window */
	Background background;
	Spaceship spaceship;
};