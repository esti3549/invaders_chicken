#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gift.h"
#include "Factory.h"

class LifeGift : public Gift
{
public:
	LifeGift(sf::Vector2f location);
	LifeGift() = default;
	~LifeGift()=default;

protected:
	static bool m_registerit;
};

inline bool LifeGift::m_registerit = Factory::registerit(
	[](sf::Vector2f location) -> std::unique_ptr<ItemExplosion> {return std::make_unique<LifeGift>(location); });
