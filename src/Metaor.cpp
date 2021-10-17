#include "..\include\Metaor.h"

Metaor::Metaor(sf::Vector2f location):Enemy(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("RedStone"));
	m_toDie = 1;
}

void Metaor::move(sf::Time deltaTime)
{
	m_direction = calculateDirection(Down);
	calculateRoad(m_direction, METAOR_SPEED);
	m_sprite.move(m_direction * deltaTime.asSeconds());
}

