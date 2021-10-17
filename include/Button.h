#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(sf::Vector2f location);
	~Button() = default;
	void draw(sf::RenderWindow& window);
	sf::Sprite getSprite();
	virtual bool handleClick(sf::RenderWindow& window) = 0;

protected:
	sf::Sprite m_sprite;
};
