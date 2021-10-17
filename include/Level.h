#pragma once
#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
#include "Utilities.h"
#include "Factory.h"
#include "DataDisplay.h"
#include "Recources.h"
#include "Enemy.h"
#include "Agg.h"
#include "Bullet.h"
#include "CollisionHandling.h"
#include <memory>
#include <vector>
#include <string>
#include <fstream>

class Level
{
public:
	Level(int& numOfLevel);
	~Level() = default;
	 bool run(SpaceShip& actor, sf::RenderWindow& window, const std::string& levelFile);

private:
	std::ifstream m_file;
	std::vector<std::unique_ptr<Enemy>> m_metaor;
	std::vector<std::unique_ptr<TypeOfChicken>> m_ChickenVec;
	std::vector<std::unique_ptr<Bullet>> m_eggs;
	std::vector<std::unique_ptr< ItemExplosion >> m_itemVec;
	sf::Sprite m_background;
	sf::Sprite m_repaetBackground;
	sf::Sprite m_boom;
	sf::Clock m_clock;
	DataDisplay m_data;
	int m_numOfLevel;
	bool m_isEgg;
	int m_iter;

	void openLevelFile(const std::string& levelFile);
	void readFile();
	void insertObjects(int row, int col, std::string nameObject, sf::Vector2f location);
	void createMetaor(int row, int col, std::string nameObject, sf::Vector2f location);
	void drawObject(sf::RenderWindow& window, SpaceShip& actor);
	void move(SpaceShip& actor);
	void creatEgg();
	void eventHandler(sf::RenderWindow& window, SpaceShip& actor);
	sf::Time getDeltaTime();
	void repeatBackground();
	void mainColision(SpaceShip& actor, sf::RenderWindow& window);
	void chickenCollisionWithBullet(sf::RenderWindow& window, SpaceShip& actor);
	void metaorCollisionWithBullet(sf::RenderWindow& window, SpaceShip& actor);
	void spaceShipCollisionWithEgg(SpaceShip& actor);
	void spaceShipCollisionWithChicken(SpaceShip& actor);
	void spaceShipCollisionWithItem(SpaceShip& actor); 
	void metaorCollisionWithSpaceship(SpaceShip& actor);
	void drawItem(sf::RenderWindow& window);
	void deleteObjects();
	//

};
