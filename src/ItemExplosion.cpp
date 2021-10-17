#include "ItemExplosion.h"
ItemExplosion::ItemExplosion(sf::Vector2f location):DinamicObject(location),m_iteration(EGG_ITERATION)
{
}
//-----------------------------------------------------------------------
void ItemExplosion::move(sf::Time deltaTime)
{
	if (m_sprite.getPosition().y >= HEIGHT_OF_WINDOW - 50)
	{
		m_iteration--;
		m_direction = { 0,0 };
	}
	else
	{
		m_direction = calculateDirection(Down);
		calculateRoad(m_direction, ITEM_SPEED);
		m_sprite.move(m_direction * deltaTime.asSeconds());
	}
	if (m_iteration == 0)
	{
		m_iteration = EGG_ITERATION;
		m_sprite.setColor(sf::Color::Transparent);
	}
}
