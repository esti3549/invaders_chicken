#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ItemExplosion.h"
#include "Factory.h"

class Bomb : public ItemExplosion
{
public:
	Bomb(sf::Vector2f location);
	Bomb() = default;
	~Bomb()=default;

protected:
	static bool m_registerit;
};
inline bool Bomb::m_registerit = Factory::registerit(
	[](sf::Vector2f location) -> std::unique_ptr<ItemExplosion> {return std::make_unique<Bomb>(location); });