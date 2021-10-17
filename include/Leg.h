#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ItemExplosion.h"
#include "Factory.h"

class Leg :public ItemExplosion
{
public:
	Leg(sf::Vector2f location);
	Leg() = default;
	~Leg()=default;

protected:
	static bool m_registerit;
};

inline bool Leg::m_registerit = Factory::registerit(
	[](sf::Vector2f location) -> std::unique_ptr<ItemExplosion> {return std::make_unique<Leg>(location); });