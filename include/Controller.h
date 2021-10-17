#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"
#include "Utilities.h"
class Controller
{
public:
	Controller();
	~Controller() = default;
	void run();

protected:
	sf::RenderWindow m_window;
	Menu m_menu;

};

