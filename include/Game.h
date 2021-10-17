#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "SpaceShip.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

class Game
{
public:
	Game();
	~Game() = default;
	void run(sf::RenderWindow& window);
protected:
	void resultGame(sf::RenderWindow& window, std::string screen);
	SpaceShip m_actor;
};

