#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DinamicObject.h"
#include "Recources.h"
class ItemExplosion : public DinamicObject
{
public:
	ItemExplosion(sf::Vector2f location);
	ItemExplosion() = default;
	~ItemExplosion() = default;
	virtual void move(sf::Time deltaTime) override;
protected:
	int m_iteration;
};
