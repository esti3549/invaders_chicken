#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Utilities.h>
#include <algorithm> 

class Move
{
public:
	Move();
	virtual ~Move(){}
	virtual void move(sf::Time deltaTime, sf::Sprite& sprite) = 0;
	sf::Vector2f calculateDirection(Directions index);
	bool checkLimitR(sf::Vector2f location, sf::Sprite sprite);
	bool checkLimitL(sf::Vector2f location);
	virtual int getWidth()=0;
	virtual int getHight() = 0;

protected:
	sf::Vector2f m_direction;//כיוון נוכחי
	void calculateRoad(sf::Vector2f& direction, int speed);
	int m_iterations;
};

