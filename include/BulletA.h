 #pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"
#include "Factory.h"
#include "Utilities.h"

class BulletA : public Bullet
{
public:
	BulletA(sf::Vector2f location);
	BulletA() = default;
	~BulletA() = default;
	virtual void move(sf::Time deltaTime) override;

protected:
	static bool m_registerit;
};
inline bool BulletA::m_registerit = Factory::registeritBullet("BulletA",
	[](sf::Vector2f location) -> std::unique_ptr<Bullet> {return std::make_unique<BulletA>(location); });
