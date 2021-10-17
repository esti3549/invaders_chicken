#include "..\include\Move.h"

Move::Move():m_iterations(0)
{
}

sf::Vector2f Move::calculateDirection(Directions index)
{
	sf::Vector2f direction;
	switch (index)
	{
	case Up:
		return direction = { 0 , -1 };
	case Down:
		return direction = { 0 ,  1 };
	case Left:
		return direction = { -1 ,  0 };
	case Right:
		return direction = { 1 ,  0 };
	default:
		throw std::out_of_range("Unknown direction to move");
	}
}

bool Move::checkLimitR(sf::Vector2f location, sf::Sprite sprite)
{
	return location.x + sprite.getGlobalBounds().width <= WIDTH_OF_WINDOW;
}

bool Move::checkLimitL(sf::Vector2f location)
{
	return location.x > 0;
}

void Move::calculateRoad(sf::Vector2f& direction, int speed)
{
	direction.x *= speed;
	direction.y *= speed;
}
