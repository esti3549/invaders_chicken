#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <xstddef>
#include <algorithm>
#include <memory>
#include "Enemy.h"
#include "Colide.h"
#include "Move.h"

class SpaceShip;
class TypeOfChicken : public Enemy
{
public:
	TypeOfChicken(sf::Vector2f location, std::unique_ptr<Colide> ptrColide, std::unique_ptr<Move> ptrMove);
	TypeOfChicken(sf::Vector2f location);
	TypeOfChicken() = default;
	~TypeOfChicken()=default;
	int getWidthSprite() const;
	int getHightSprite() const;
	void movePtr(sf::Time deltaTime, sf::Sprite & sprite);
	bool colidePtr();
   void spaceShipColideWithChicken(SpaceShip& actor);
	sf::Sprite& getSprite();
	bool ifDie();
protected:
	std::unique_ptr<Colide> m_ptrColide;
	std::unique_ptr< Move> m_ptrMove;
};