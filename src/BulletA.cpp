#include "..\include\BulletA.h"

BulletA::BulletA(sf::Vector2f location):Bullet(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("Bullet"));
}
//---------------------------------------------------------------------
void BulletA::move(sf::Time deltaTime)
{
	m_direction = calculateDirection(Up);
	calculateRoad(m_direction, BULLET_SPEED);
	m_sprite.move(m_direction * deltaTime.asSeconds());
}
