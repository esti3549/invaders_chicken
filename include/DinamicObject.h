#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "Recources.h"
#include <vector>
#include "Utilities.h"
class DinamicObject : public Object
{
public:
	DinamicObject(sf::Vector2f location);
	DinamicObject() = default;
	~DinamicObject()=default;
	//virtual void move(sf::Time deltaTime) = 0;
	bool checkLimitR(sf::Vector2f location);
	bool checkLimitL(sf::Vector2f location);
	bool checkLimitSpaceShip(sf::Vector2f location);
	sf::Vector2f calculateDirection(Directions index);
	/*void setSound(std::string, float vol =100);*/
protected:
	//int m_spead;//מהירות
	sf::Vector2f m_direction;//כיוון נוכחי
	sf::Sound m_sound;
	void calculateRoad(sf::Vector2f& direction, int speed);
};
