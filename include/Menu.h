#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Recources.h"
#include "PlayButton.h"
#include "HelpButton.h"
#include "ExitButton.h"

class Menu
{
public:
	Menu();
	~Menu() = default;
	void draw(sf::RenderWindow & window);
	void run(sf::RenderWindow& window);

protected:
	std::vector< std::unique_ptr <Button> > m_menu;
	sf::Sprite m_sprite;//מחזיק את תמונת הרקע של התפריט

	bool isContain(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window, Button& button);
};



