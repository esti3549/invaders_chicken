#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
#include "Recources.h"
#include "Factory.h"

class Agg : public Bullet
{
public:
	Agg(sf::Vector2f location);
	Agg() = default;
	~Agg()=default;
	virtual void move(sf::Time deltaTime) override;

protected:
	int m_iteration;
	sf::Texture m_brokenEgg;
	static bool m_registerit;
};

inline bool Agg::m_registerit = Factory::registeritBullet("Egg",
	[](sf::Vector2f location) -> std::unique_ptr<Bullet> {return std::make_unique<Agg>(location); });
