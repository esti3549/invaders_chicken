#include "..\include\LifeGift.h"

LifeGift::LifeGift(sf::Vector2f location) :Gift(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("LifeGift"));
}
