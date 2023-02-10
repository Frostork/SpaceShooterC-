#include "Spaceship.h"
#include <iostream>
#include <Windows.h>

Spaceship::Spaceship(double _x, double _y) : x(_x), y(_y)
{
    if (SpaceshipTexture.loadFromFile("spaceship.png") == false) {
        std::cout << "Erreur de chargement" << std::endl;
    };

    SpaceshipSprite.setTexture(SpaceshipTexture);
    speed = 350;
}

void Spaceship::Move()
{
    auto time_elapsed = clock_ship.getElapsedTime().asSeconds();
    clock_ship.restart();

    if (GetKeyState('Q') & 0x8000) {
        x -= speed * time_elapsed;
    }
    if (GetKeyState('D') & 0x8000) {
        x += speed * time_elapsed;
    }
    if (GetKeyState('Z') & 0x8000) {
        y -= speed * time_elapsed;
    }
    if (GetKeyState('S') & 0x8000) {
        y += speed * time_elapsed;
    }
}


void Spaceship::display(sf::RenderWindow& window)
{
    window.draw(SpaceshipSprite);

    //Debug Player Position
    //std::cout << "Spaceship at position (" << this->x << "," << this->y << ")" << std::endl;
}

void Spaceship::fire()
{
    std::cout << "Fire !" << std::endl;
}

void Spaceship::collision()
{
    std::cout << "Collision" << std::endl;
}

void Spaceship::update()
{
    SpaceshipSprite.setPosition(x, y);
}
