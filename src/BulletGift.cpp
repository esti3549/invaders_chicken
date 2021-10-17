#include "..\include\BulletGift.h"

BulletGift::BulletGift(sf::Vector2f location):Gift(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("BulletGift"));
}
