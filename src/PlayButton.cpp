#include "PlayButton.h"

PlayButton::PlayButton(sf::Vector2f location):Button(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("StartButton"));
}

bool PlayButton::handleClick(sf::RenderWindow& window)
{
	return true;
}
