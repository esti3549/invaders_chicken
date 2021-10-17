#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ItemExplosion.h"

class SpaceShip;
class Colide
{
public:
	Colide();
	virtual ~Colide()=default;
	virtual bool colide() = 0;
 void colideWithSpaceship(SpaceShip& actor) ;
	int getToDie();
	void setToDie(int num);
protected:
	int m_toDie;
	sf::Sprite m_sprite;
};
