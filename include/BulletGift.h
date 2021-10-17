#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gift.h"
#include "Factory.h"

class BulletGift :public Gift
{
public:
	BulletGift(sf::Vector2f location);
	BulletGift() = default;
	~BulletGift() = default;

protected:
	static bool m_registerit;
};

inline bool BulletGift::m_registerit = Factory::registerit(
	[](sf::Vector2f location) -> std::unique_ptr<ItemExplosion> {return std::make_unique<BulletGift>(location); });
