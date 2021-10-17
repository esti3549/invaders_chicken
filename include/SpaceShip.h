#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DinamicObject.h"
#include "CollisionHandling.h"
#include "TypeOfChicken.h"
#include "Enemy.h"
#include "Recources.h"
#include "Factory.h"
#include "Bullet.h"

class SpaceShip : public DinamicObject
{
public:
	SpaceShip(sf::Vector2f location);
	SpaceShip();
	~SpaceShip() = default;
	int getLives() const; 
	int getScore() const;
	bool getProtected();
	void setLife(int num);
	void setScore(int num);
	void setProtected(bool flag);
	void handleEvent(sf::Keyboard::Key key);
	virtual void move(sf::Time deltaTime) override;
	void moveBullet(sf::Time deltaTime);
	void drawBullet(sf::RenderWindow& window);
	bool chickenCollisionWithBullet(TypeOfChicken& chicken);
	bool metaorCollisionWithBullet(Enemy& metaor);
	void deleteBullet();

protected:
	std::vector< std::unique_ptr < Bullet>> m_bulletVec;
	int m_numLife;
	int m_score;
	bool m_isProtected;
};

