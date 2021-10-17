
#pragma once
#include <SFML/Graphics.hpp>
#include "ItemExplosion.h"
#include "DinamicObject.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BehaviorBigChicken.h"
#include "BehaviorSmallChicken.h"
#include "MoveBigChicken.h"
#include "MoveSmallChicken.h"
#include "TypeOfChicken.h"
#include <iostream>
#include <vector>

typedef std::vector<std::unique_ptr<ItemExplosion>(*)(sf::Vector2f)> items;
typedef std::map<std::string, std::unique_ptr<Enemy>(*)(sf::Vector2f)> chickenMap;
typedef std::map<std::string, std::unique_ptr<Bullet >(*)(sf::Vector2f)> BulletMap;

class Factory
{
public:

	static bool registerit(std::unique_ptr<ItemExplosion>(*function)(sf::Vector2f location));//עבור הוקטור
	static std::unique_ptr<ItemExplosion> create(sf::Vector2f location);//עבור הוקטוור

	static bool registerit(const std::string& name, std::unique_ptr<Enemy>(*function)(sf::Vector2f location));//עבור המפה
	static std::unique_ptr<Enemy> create(const std::string& name, sf::Vector2f location);//עבור יצירת המטאור

	static bool registeritBullet(const std::string& name, std::unique_ptr<Bullet>(*function)(sf::Vector2f location));//עבור המפה
	static std::unique_ptr<Bullet> createBullet(const std::string& name, sf::Vector2f location);//עבור המפה

	static std::unique_ptr<TypeOfChicken>createTypeOfChicken(const std::string& taype, sf::Vector2f location);//עבור יצירת האובייקט 

protected:
	static items& getItem();
	//---------------------------
	static chickenMap& getChickenMap();
	//---------------------------
	static BulletMap& getMapBullet();
};
