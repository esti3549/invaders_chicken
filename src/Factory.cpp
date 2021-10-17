#include "Factory.h"

bool Factory::registerit(std::unique_ptr<ItemExplosion>(*function)(sf::Vector2f location))
{
	getItem().emplace_back(function);
	return true;
}
//--------------------------------------------------------------------------------
std::unique_ptr<ItemExplosion> Factory::create(sf::Vector2f location)
{
	int typeOfItem = rand() % getItem().size();
	return getItem()[typeOfItem](location);
}
//--------------------------------------------------------------------------------
bool Factory::registerit(const std::string& name, std::unique_ptr<Enemy>(*function)(sf::Vector2f location))
{
	getChickenMap().emplace(name, function);
	return true;
}
//--------------------------------------------------------------------------------
std::unique_ptr<Bullet> Factory::createBullet(const std::string& name, sf::Vector2f location)
{
	auto it = getMapBullet().find(name);
	if (it == getMapBullet().end())
		return nullptr;
	return it->second(location);
}
//--------------------------------------------------------------------------------
std::unique_ptr<TypeOfChicken> Factory::createTypeOfChicken(const std::string& taype, sf::Vector2f location)
{
	if (taype == "SmallChicken")
	{
		std::unique_ptr ptrColide = std::make_unique< BehaviorSmallChicken>();
		std::unique_ptr ptrMove = std::make_unique< MoveSmallChicken>();
		return std::make_unique<TypeOfChicken>(location, std::move(ptrColide), std::move(ptrMove));
	}
	if (taype == "BigChicken")
	{
		std::unique_ptr ptrColide = std::make_unique< BehaviorBigChicken>();
		std::unique_ptr ptrMove = std::make_unique< MoveBigChicken>();
		return std::make_unique<TypeOfChicken>(location, std::move(ptrColide), std::move(ptrMove));
	}
	return NULL;
}
//--------------------------------------------------------------------------------
std::unique_ptr<Enemy> Factory::create(const std::string& name, sf::Vector2f location)
{
	auto it = getChickenMap().find(name);
	if (it == getChickenMap().end())
		return nullptr;
	return it->second(location);
}
//--------------------------------------------------------------------------------
bool Factory::registeritBullet(const std::string& name, std::unique_ptr<Bullet>(*function)(sf::Vector2f location))
{
	getMapBullet().emplace(name, function);
	return true;
}
//--------------------------------------------------------------------------------
items& Factory::getItem()
{
	static items m_items;
	return m_items;
}
//--------------------------------------------------------------------------------
chickenMap& Factory::getChickenMap()
{
	static chickenMap m_map;
	return m_map;
}
//--------------------------------------------------------------------------------
BulletMap& Factory::getMapBullet()
{
	static BulletMap m_map;
	return m_map;
}

