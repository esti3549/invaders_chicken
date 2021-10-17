#include "CollisionHandling.h"
#include "Agg.h"
#include "SpaceShip.h"
#include "LifeGift.h"
#include "Bomb.h"
#include "BulletGift.h"
#include "Leg.h"
#include "Metaor.h"
#include "BulletA.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

namespace // anonymous namespace — the standard way to make function "static"
{
	void ShipEgg(Object& spaceShip, Object& egg)
	{
		SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
		if (!ship.getProtected())
		{
			Recources::getInstance().setAndPlaySound("Splat_egg", 30);
			ship.setLife(-1);//הורדת 1 מחייוו של השחקן
		}
	}
	//--------------------------------------------------
	void shipLifeGift(Object& spaceShip, Object& lifeGift)
	{
		SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
		ship.setLife(2);
	}
	//---------------------------------------------------
	void shipBomb(Object& spaceShip, Object& bomb)
	{
		SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
		ship.setLife(-2);
		ship.setProtected(false);
		Recources::getInstance().setAndPlaySound("shoot", 30);
	}
	//-----------------------------------------------------
	void shipLeg(Object& spaceShip, Object& leg)
	{
		SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
		ship.setScore(1234);
		Recources::getInstance().setAndPlaySound("chewing");
	}
	//-----------------------------------------------------
	void metaorShip(Object& metaor, Object& spaceShip)
	{
		SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
		if (!ship.getProtected())
		{
			Recources::getInstance().setAndPlaySound("shoot", 30);
			ship.setLife(-1);
		}
	}
	//-----------------------------------------------------
	void bulletMetaor(Object& metaor, Object& bullet)
	{
		Recources::getInstance().setAndPlaySound("shoot", 30);
	}
	//-----------------------------------------------------
	void shipBulletGift(Object& spaceShip, Object& bulletGift)
	{
		SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
		ship.setProtected(true);
		Recources::getInstance().setAndPlaySound("Protect",20);
	}
	//-----------------------------------------------------
	using HitFunctionPtr = void (*)(Object&, Object&);//מצביע לפונקציית הטיפול בהתנגשות שתהיה במפה
	using Key = std::pair<std::type_index, std::type_index>;//שני האובייקטים שבנהם הייתה התנגשות
	using HitMap = std::map<Key, HitFunctionPtr>;//מפה

	HitMap initializeCollisionMap()
	{
		HitMap ColisionMap;
		ColisionMap[Key(typeid(SpaceShip),    typeid(Agg))] = &ShipEgg;
		ColisionMap[Key(typeid(SpaceShip),    typeid(LifeGift))] = &shipLifeGift;
		ColisionMap[Key(typeid(SpaceShip),    typeid(Bomb))] = &shipBomb;
		ColisionMap[Key(typeid(SpaceShip),    typeid(Leg))] = &shipLeg;
		ColisionMap[Key(typeid(Metaor),       typeid(SpaceShip))] = &metaorShip;
		ColisionMap[Key(typeid(SpaceShip),    typeid(BulletGift))] = &shipBulletGift;
		ColisionMap[Key(typeid(Metaor),       typeid(BulletA))] = &bulletMetaor;

		return ColisionMap;
	}



	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}
}
//-------------------------------------------------------------------------
void processCollision(Object& object1, Object& object2)
{
	auto ColisionMap = lookup(typeid(object1), typeid(object2));
	if (!ColisionMap)
	{
		throw UnknownCollision(object1, object2);
	}
	ColisionMap(object1, object2);
}
