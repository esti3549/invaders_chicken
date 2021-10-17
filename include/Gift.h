#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ItemExplosion.h"

class Gift :public ItemExplosion
{
public:
	Gift(sf::Vector2f location);
	Gift() = default;
	~Gift()=default;

protected:

};

