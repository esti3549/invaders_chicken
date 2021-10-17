#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "DinamicObject.h"
#include "Enemy.h"
#include "Factory.h"

class Metaor: public Enemy
{
public:
	Metaor(sf::Vector2f location);
	Metaor() = default;
	~Metaor() = default;
	virtual void move(sf::Time deltaTime) override;
//	virtual void updateToDie() override;

protected:
	static bool m_registerit;
};
inline bool Metaor::m_registerit = Factory::registerit("Metaor",
	[](sf::Vector2f location) -> std::unique_ptr<Enemy> {return std::make_unique<Metaor>(location); });
