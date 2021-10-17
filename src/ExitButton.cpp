#include "ExitButton.h"

ExitButton::ExitButton(sf::Vector2f location) :Button(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("ExitButton"));
}

bool ExitButton::handleClick(sf::RenderWindow& window)
{
	window.close();
	exit(EXIT_SUCCESS);
	return false;
}
