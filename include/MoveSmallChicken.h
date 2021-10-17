#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Move.h"
#include "Recources.h"

class MoveSmallChicken :public Move
{
public:
	MoveSmallChicken();
	virtual ~MoveSmallChicken() {};
	virtual void move(sf::Time deltaTime, sf::Sprite& sprite) override;
	virtual int getWidth() override;
	virtual int getHight() override;

protected:
	static bool m_register;
};