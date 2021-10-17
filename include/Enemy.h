#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DinamicObject.h"
#include "Recources.h"
#include <vector>
 
class Enemy : public DinamicObject
{
public:
	Enemy(sf::Vector2f location);
	~Enemy()=default;
	void changeImg();
	int getToDie();
	void setToDie(int num);

protected:
	int m_iterations;
	int m_toDie;
};

