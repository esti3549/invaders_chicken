#include "Level.h"

Level::Level(int& numOfLevel) :m_background(Recources::getInstance().getImg("Background1")),
m_repaetBackground(Recources::getInstance().getImg("Background1")),
m_numOfLevel(numOfLevel), m_isEgg(false), m_clock(), m_iter(BOOM_ITERATION)
{
	Recources::getInstance().getMusic("melody")->play();
	Recources::getInstance().getMusic("melody")->setLoop(true);
	m_repaetBackground.setPosition({ 0,-HEIGHT_OF_WINDOW });
	m_boom.setTexture(Recources::getInstance().getImg("boom"));
	m_boom.setPosition({ -110,-100 });
}
//--------------------------------------------------------------------
//Main function that running the current level.
bool Level::run(SpaceShip& actor, sf::RenderWindow& window, const std::string& levelFile)
{
	openLevelFile(levelFile);
	readFile();
	while (actor.getLives() >= 0)//Loop running until the player have life
	{
		window.clear();
		drawObject(window, actor);//Function that draw all object
		m_data.displayData(actor.getLives(), actor.getScore(), m_numOfLevel, window);

		move(actor);
		actor.move(getDeltaTime());
		eventHandler(window, actor);
		actor.drawBullet(window);
		actor.moveBullet(getDeltaTime());

		if (m_isEgg)//If in this level we ned to create eggs.
			creatEgg();

		mainColision(actor, window);//Function that responsible about the whole collisions.
		drawItem(window);
		actor.draw(window);
		window.display();

		//If our objects went out of screen we will delete them.
		deleteObjects();
		actor.deleteBullet();

		//If all objects in this level were died we will read the next level.
		if (m_ChickenVec.size() == 0 && m_metaor.size() == 0 && m_iter == BOOM_ITERATION)
		{
			actor.setProtected(false);
			return true;
		}
		//If the player lives were end the game is is over.
		if (actor.getLives() == 0)
			return false;
	}
	return false;
}
//----------------------------------------------------------------------------------------
//Open the file and check if it opened successfully
void Level::openLevelFile(const std::string& levelFile)
{
	m_file.open(levelFile);
	if (!m_file.is_open())
		throw std::ios_base::failure("Can't open the file");
}
//----------------------------------------------------------------------------------------
//Reading the file
void Level::readFile()
{
	char c, isEgg;
	int row, col;
	sf::Vector2f location;

	m_file >> row >> col >> c >> location.x >> location.y >> isEgg;

	if (isEgg == 'y')
		m_isEgg = true;
	else
		m_isEgg = false;

	switch (c)
	{
	case SMALL_CHICKEN:
		insertObjects(row, col, "SmallChicken", location);
		break;
	case BIG_CHICKEN:
		insertObjects(row, col, "BigChicken", location);
		break;
	case METAOR:
		createMetaor(row, col, "Metaor", location);
		break;
	default:
		throw std::out_of_range("Unknown object to create");
	}
}
//----------------------------------------------------------------------------------------
//Create objects according to the file
void Level::insertObjects(int row, int col, std::string nameObject, sf::Vector2f location)
{
	sf::Vector2f c_location = location;
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			m_ChickenVec.emplace_back(Factory::createTypeOfChicken(nameObject, location));;//הכנסה למבנה נתונים
			location.x += m_ChickenVec[j]->getWidthSprite() + 10;
		}
		location.x = c_location.x;
		location.y += m_ChickenVec[i]->getHightSprite() + 10;
	}
}
//---------------------------------------------------------------------------------------
//Create the metaors in random places.
void Level::createMetaor(int row, int col, std::string nameObject, sf::Vector2f location)
{
	for (int i = 0; i < (row * col); i++)
	{
		int x = rand() % WIDTH_OF_WINDOW;
		int y = rand() % (HEIGHT_OF_WINDOW * 20);
		y *= -1;
		location.x = float(x);
		location.y = float(y);
		m_metaor.emplace_back(Factory::create(nameObject, location));//הכנסה למבנה נתונים
		if (i % 5 == 0)
			m_metaor[i]->changeImg();
	}
}
//----------------------------------------------------------------------------------------
//Draw all objects.
void Level::drawObject(sf::RenderWindow& window, SpaceShip& actor)
{
	repeatBackground();
	window.draw(m_background);
	window.draw(m_repaetBackground);

	for (const auto& obj : m_metaor)
	{
		obj->draw(window);
	}
	for (const auto& chicken : m_ChickenVec)
	{
		chicken->draw(window);
	}
	for (const auto& obj : m_eggs)
	{
		obj->draw(window);
	}

	if (m_iter != 0 && m_iter != BOOM_ITERATION) {
		window.draw(m_boom);
		m_iter -= 1;
	}
	else if (m_iter == 0)
		m_iter = BOOM_ITERATION;
}
//----------------------------------------------------------------------------------------
//Move all objects.
void Level::move(SpaceShip& actor)
{
	auto deltaTime = m_clock.getElapsedTime();
	m_background.move({ 0, BACKGROUND_SPEED * deltaTime.asSeconds() });
	m_repaetBackground.move({ 0, BACKGROUND_SPEED * deltaTime.asSeconds() });

	for (const auto& obj : m_metaor)
	{
		obj->move(deltaTime);
	}
	for (const auto& chicken : m_ChickenVec)
	{
		chicken->movePtr(deltaTime, chicken->getSprite());
	}
	for (const auto& obj : m_eggs)
	{
		obj->move(deltaTime);
	}
	for (const auto& item : m_itemVec)
	{
		item->move(deltaTime);
	}
}
//----------------------------------------------------------------------------------------
//Creat Eggs as long as chickens exist.
void Level::creatEgg()
{
	sf::Vector2f position;
	int random;
	if (m_ChickenVec.size() > 0)
	{
		random = rand() % RANGE;
		if (random == 2)
		{
			int chick = rand() % m_ChickenVec.size();
			position = m_ChickenVec[chick]->getPositionSprite();
			position.x += (m_ChickenVec[chick]->getWidthSprite() / 2);
			position.y += (m_ChickenVec[chick]->getHightSprite() - 3);
			m_eggs.emplace_back(Factory::createBullet("Egg", position));//Create new egg
		}
	}
	for (int i = 0; i < m_eggs.size(); i++)//If we need to erase any egg
		if (m_eggs[i]->getColor() == sf::Color::Transparent)
		{
			m_eggs.erase(m_eggs.begin() + i);
			i--;
		}
}
//---------------------------------------------------------------------------------------
//User input management
void Level::eventHandler(sf::RenderWindow& window, SpaceShip& actor)
{
	auto event = sf::Event{};
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
			break;
		case sf::Event::KeyPressed:
		{
			actor.handleEvent(event.key.code);
			break;
		}
		default:
			break;
		}
	}
}
//------------------------------------------------------------------
sf::Time Level::getDeltaTime()
{
	sf::Time deltaTime = m_clock.restart();
	return deltaTime;
}
//-------------------------------------------------------------------
//Moving the background.
void Level::repeatBackground()
{
	sf::Vector2f strtingPosition = { 0, -HEIGHT_OF_WINDOW };
	if (m_background.getPosition().y >= HEIGHT_OF_WINDOW)
		m_background.setPosition(strtingPosition);
	if (m_repaetBackground.getPosition().y >= HEIGHT_OF_WINDOW)
		m_repaetBackground.setPosition(strtingPosition);
}
//-------------------------------------------------------------------
//Function that responsible about the whole collisions.
void Level::mainColision(SpaceShip& actor, sf::RenderWindow& window)
{
	spaceShipCollisionWithEgg(actor);

	spaceShipCollisionWithChicken(actor);

	chickenCollisionWithBullet(window, actor);

	spaceShipCollisionWithItem(actor);

	metaorCollisionWithBullet(window, actor);

	metaorCollisionWithSpaceship(actor);
}
//-------------------------------------------------------------------
void Level::chickenCollisionWithBullet(sf::RenderWindow& window, SpaceShip& actor)
{
	sf::Vector2f position;
	for (int i = 0; i < m_ChickenVec.size(); i++)
	{
		if (actor.chickenCollisionWithBullet(*m_ChickenVec[i]))
		{
			actor.setScore(1234);

			position = m_ChickenVec[i]->getPositionSprite();
			position.x += (m_ChickenVec[i]->getWidthSprite() / 2);
			position.y += (m_ChickenVec[i]->getHightSprite());

			m_itemVec.emplace_back(Factory::create(position));

			if (m_ChickenVec[i]->ifDie())
			{
				auto scaleX = m_ChickenVec[i]->getWidthSprite() * 1.00f / m_boom.getTexture()->getSize().x;
				auto scaleY = m_ChickenVec[i]->getHightSprite() * 1.00f / m_boom.getTexture()->getSize().y;
				m_boom.setScale(scaleX, scaleY);
				m_boom.setPosition(m_ChickenVec[i]->getPositionSprite());

				m_iter -= 1;
				m_ChickenVec.erase(m_ChickenVec.begin() + i);
				i--;
			}
		}
	}
}
//-------------------------------------------------------------------------
void Level::metaorCollisionWithBullet(sf::RenderWindow& window, SpaceShip& actor)
{
	sf::Vector2f position;
	for (int i = 0; i < m_metaor.size(); i++)
	{
		if (actor.metaorCollisionWithBullet(*m_metaor[i]))
		{
			actor.setScore(1234);

			position = m_metaor[i]->getPositionSprite();
			position.x += (m_metaor[i]->getWidthSprite() / 2);
			position.y += (m_metaor[i]->getHightSprite());

			if (m_metaor[i]->getToDie() == 0)
			{
				auto scaleX = m_metaor[i]->getWidthSprite() * 1.00f / m_boom.getTexture()->getSize().x;
				auto scaleY = m_metaor[i]->getHightSprite() * 1.00f / m_boom.getTexture()->getSize().y;
				m_boom.setScale(scaleX, scaleY);
				m_boom.setPosition(m_metaor[i]->getPositionSprite());

				m_iter -= 1;
				m_metaor.erase(m_metaor.begin() + i);
				i--;
			}
		}
	}
}
//-------------------------------------------------------------------
void Level::spaceShipCollisionWithEgg(SpaceShip& actor)
{
	for (int i = 0; i < m_eggs.size(); i++)
		if (actor.getRectangle().intersects(m_eggs[i]->getRectangle()))//בדיקה אם הייתה התנגשות
		{
			processCollision(actor, *m_eggs[i]);
			if (!actor.getProtected())
				m_eggs.erase(m_eggs.begin() + i);
		}
}
//-------------------------------------------------------------------
void Level::spaceShipCollisionWithChicken(SpaceShip& actor)
{
	for (int i = 0; i < m_ChickenVec.size(); i++)
	{
		if (actor.getRectangle().intersects(m_ChickenVec[i]->getRectangle()))
			m_ChickenVec[i]->spaceShipColideWithChicken(actor);
	}
}
//-------------------------------------------------------------------
void Level::spaceShipCollisionWithItem(SpaceShip& actor)
{
	for (int i = 0; i < m_itemVec.size(); i++)
		if (actor.getRectangle().intersects(m_itemVec[i]->getRectangle()))//בדיקה אם הייתה התנגשות
		{
			processCollision(actor, *m_itemVec[i]);
			m_itemVec.erase(m_itemVec.begin() + i);
			i--;
		}
}
//-------------------------------------------------------------------
void Level::metaorCollisionWithSpaceship(SpaceShip& actor)
{
	for (int i = 0; i < m_metaor.size(); i++)
	{
		if (m_metaor[i]->getRectangle().intersects(actor.getRectangle()))
		{
			m_metaor[i]->setToDie(-1);
			processCollision(*m_metaor[i], actor);
			if (m_metaor[i]->getToDie() == 0)
			{
				if (!actor.getProtected())
				{
					m_metaor.erase(m_metaor.begin() + i);
					i--;
				}
			}
		}
	}
}
//-------------------------------------------------------------------
void Level::drawItem(sf::RenderWindow& window)
{
	for (const auto& item : m_itemVec)
		item->draw(window);
}
//-------------------------------------------------------------------
void Level::deleteObjects()
{
	for (int i = 0; i < m_metaor.size(); i++)
	{
		if (m_metaor[i]->checkOutSideDownLimit())
		{
			m_metaor.erase(m_metaor.begin() + i);
			i--;
		}
	}
}


