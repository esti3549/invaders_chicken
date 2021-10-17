#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Move.h"
#include "Recources.h"

class MoveBigChicken : public Move
{
public:
	MoveBigChicken();
	virtual ~MoveBigChicken() {};
	virtual void move(sf::Time deltaTime, sf::Sprite& sprite) override;
	virtual int getWidth() override;
	virtual int getHight() override;
protected:
	static bool m_register;
	int m_downIterations;
	int m_upIterations;
	int m_leftIterations;
	int m_rightIterations;
};
