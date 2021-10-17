#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DinamicObject.h"
#include "ItemExplosion.h"

class Bullet : public DinamicObject
{
public:
	Bullet(sf::Vector2f location);
	Bullet() = default;
	~Bullet() = default;
	virtual void move(sf::Time deltaTime) = 0;
protected:

};
