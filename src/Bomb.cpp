#include "..\include\Bomb.h"

Bomb::Bomb(sf::Vector2f location):ItemExplosion(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("bomb"));
}
