#include "Button.h"

Button::Button(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

sf::Sprite Button::getSprite()
{
	return m_sprite;
}
