#include "..\include\TypeOfChicken.h"
#include "SpaceShip.h"

TypeOfChicken::TypeOfChicken(sf::Vector2f location, std::unique_ptr<Colide> ptrColide, std::unique_ptr< Move> ptrMove)
	:Enemy(location),m_ptrColide(std::move(ptrColide)),m_ptrMove(std::move(ptrMove))
{
}

TypeOfChicken::TypeOfChicken(sf::Vector2f location): Enemy(location)
{
}

int TypeOfChicken::getWidthSprite() const
{
	return m_ptrMove->getWidth();
}

int TypeOfChicken::getHightSprite() const
{
	return m_ptrMove->getHight();
}

void TypeOfChicken::movePtr(sf::Time deltaTime, sf::Sprite& sprite)
{
	m_ptrMove->move(deltaTime, sprite);
}

bool TypeOfChicken::colidePtr()
{
	if (m_ptrColide->colide())
		return true;
	return false;
}

void TypeOfChicken::spaceShipColideWithChicken(SpaceShip& actor)
{
	m_ptrColide->colideWithSpaceship(actor);
}


sf::Sprite& TypeOfChicken::getSprite()
{
	return m_sprite;
}

bool TypeOfChicken::ifDie()
{
	if (m_ptrColide->getToDie() == 0)
		return true;
	return false;
}
