#include "..\include\Leg.h"

Leg::Leg(sf::Vector2f location):ItemExplosion(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("Leg1"));
}
