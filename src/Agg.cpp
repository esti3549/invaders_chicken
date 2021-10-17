#include "Agg.h"

Agg::Agg(sf::Vector2f location) :Bullet(location), m_brokenEgg(Recources::getInstance().getImg("BrokenEgg")),m_iteration(EGG_ITERATION)
{
	m_sprite.setTexture(Recources::getInstance().getImg("Egg"));
}
//----------------------------------------------------------
void Agg::move(sf::Time deltaTime)
{
	if (m_sprite.getPosition().y >= HEIGHT_OF_WINDOW - 50)
	{
		m_iteration--;
		m_sprite.setTexture(m_brokenEgg, true);
		m_direction = calculateDirection(Stop);
	}
	else
	{
		m_direction = calculateDirection(Down);
		calculateRoad(m_direction, EGG_SPEED);
		m_sprite.move(m_direction * deltaTime.asSeconds());
	}
	if (m_iteration == 0)
	{
		m_iteration = EGG_ITERATION;
		m_sprite.setColor(sf::Color::Transparent);
	}
}
