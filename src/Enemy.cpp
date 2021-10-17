#include "Enemy.h"

Enemy::Enemy(sf::Vector2f location) :DinamicObject(location), m_iterations(0)
{

}

void Enemy::changeImg()
{
	m_sprite.setTexture(Recources::getInstance().getImg("Stone"), true);
}

int Enemy::getToDie()
{
	return m_toDie;
}

void Enemy::setToDie(int num)
{
	m_toDie += num;
}
