#include "DinamicObject.h"

DinamicObject::DinamicObject(sf::Vector2f location):Object(location)
{

}
//------------------------------------------------------------------------------
bool DinamicObject::checkLimitR(sf::Vector2f location)
{
	return location.x + m_sprite.getGlobalBounds().width <= WIDTH_OF_WINDOW;
}
//------------------------------------------------------------------------------
bool DinamicObject::checkLimitL(sf::Vector2f location)
{
	return location.x > 0;
}
//------------------------------------------------------------------------------
bool DinamicObject::checkLimitSpaceShip(sf::Vector2f location)
{
	return(location.x >= 0 && location.x + m_sprite.getGlobalBounds().width <= WIDTH_OF_WINDOW &&
		   location.y >= 0 && location.y + m_sprite.getGlobalBounds().height <= HEIGHT_OF_WINDOW);
}
//-----------------------------------------------------------------------------
sf::Vector2f DinamicObject::calculateDirection(Directions index)
{
	sf::Vector2f direction;
	switch (index)
	{
	case Up:
		return direction = {  0 , -1 };
	case Down:
		return direction = {  0 ,  1 };
	case Left:
		return direction = { -1 ,  0 };
	case Right:
		return direction = {  1 ,  0 };
	case Stop:
		return direction = { 0 ,  0 };
	default:
		throw std::out_of_range("Unknown direction to move");
	}
}
//------------------------------------------------------------------------------
void DinamicObject::calculateRoad(sf::Vector2f& direction, int speed)
{
	direction.x *= speed;
	direction.y *= speed;
}
//------------------------------------------------------------------------------

