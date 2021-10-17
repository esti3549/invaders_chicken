#include "..\include\SpaceShip.h"

SpaceShip::SpaceShip(sf::Vector2f location) :DinamicObject(location), m_score(0), m_numLife(5), m_isProtected(false)
{
	m_sprite.setTexture(Recources::getInstance().getImg("SpaceShip"));
}
//--------------------------------------------------------------------------------------
SpaceShip::SpaceShip() : m_score(0), m_numLife(5), m_isProtected(false)
{
}
//--------------------------------------------------------------------------------------
int SpaceShip::getLives() const
{
	return m_numLife;
}
//--------------------------------------------------------------------------------------
int SpaceShip::getScore() const
{
	return m_score;
}
//-------------------------------------------------------------------------------------
bool SpaceShip::getProtected()
{
	return m_isProtected;
}
//--------------------------------------------------------------------------------------
void SpaceShip::setLife(int num)
{
	m_numLife += num;
}
//--------------------------------------------------------------------------------------
void SpaceShip::setScore(int num)
{
	m_score += num;
}
//--------------------------------------------------------------------------------------
void SpaceShip::setProtected(bool flag)
{
	m_isProtected = flag;
	if (m_isProtected)
	{
		m_sprite.setPosition(m_sprite.getPosition().x, 620);
		m_sprite.setTexture(Recources::getInstance().getImg("ProtectedShip"), true);
	}
	else
	{
		m_sprite.setPosition(m_sprite.getPosition().x, 650);
		m_sprite.setTexture(Recources::getInstance().getImg("SpaceShip"), true);
	}
}
//--------------------------------------------------------------------------------------
void SpaceShip::handleEvent(sf::Keyboard::Key key)
{
	sf::Vector2f position;
	switch (key)
	{
	case sf::Keyboard::Left:
		m_direction = calculateDirection(Left);
		calculateRoad(m_direction, SPACE_SHIP_SPEED);
		break;
	case sf::Keyboard::Right:
		m_direction = calculateDirection(Right);
		calculateRoad(m_direction, SPACE_SHIP_SPEED);
		break;
	case sf::Keyboard::Up:
		position = m_sprite.getPosition();
		position.x += (m_sprite.getGlobalBounds().width / 2 -12);
		position.y -= 32;// (m_bulletVec[m_bulletVec.size()]->getHightSprite());
		m_bulletVec.emplace_back((Factory::createBullet("BulletA", position)));
		m_score += 1235;
		m_direction = calculateDirection(Stop);
		break;
	case sf::Keyboard::Down:
		m_direction = calculateDirection(Stop);
		break;
	case sf::Keyboard::Space:
		m_direction = calculateDirection(Stop);
		break;
	default:
		break;
	}
}
//--------------------------------------------------------------
void SpaceShip::move(sf::Time deltaTime)
{
	if (checkLimitSpaceShip((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		m_sprite.move(m_direction * deltaTime.asSeconds());
}
//--------------------------------------------------------------
void SpaceShip::moveBullet(sf::Time deltaTime)
{
	for (const auto& bullet : m_bulletVec)
		bullet->move(deltaTime);
}
//--------------------------------------------------------------
void SpaceShip::drawBullet(sf::RenderWindow& window)
{
	for (const auto& bullet : m_bulletVec)
		bullet->draw(window);
}
//-------------------------------------------------------------
bool SpaceShip::chickenCollisionWithBullet(TypeOfChicken& chicken)
{
	for (int i = 0; i < m_bulletVec.size(); i++)
		if (chicken.getRectangle().intersects(m_bulletVec[i]->getRectangle()))//בדיקה אם הייתה התנגשות
		{
			if (chicken.colidePtr())
			{
				//chicken.setToDie(-1);////++++
				//processCollision(chicken, *m_bulletVec[i]);
				m_bulletVec.erase(m_bulletVec.begin() + i);
				i--;
				return true;
			}
		}
	return false;
}
bool SpaceShip::metaorCollisionWithBullet(Enemy& metaor)
{
	for (int i = 0; i < m_bulletVec.size(); i++)
		if (metaor.getRectangle().intersects(m_bulletVec[i]->getRectangle()))//בדיקה אם הייתה התנגשות
		{
			metaor.setToDie(-1);////++++
				processCollision(metaor, *m_bulletVec[i]);
				m_bulletVec.erase(m_bulletVec.begin() + i);
				i--;
				return true;
		}
	return false;
}
//-------------------------------------------------------------
void SpaceShip::deleteBullet()
{
	for (int i = 0; i < m_bulletVec.size(); i++)
	{
		if (m_bulletVec[i]->checkOutSideLimit())
		{
			m_bulletVec.erase(m_bulletVec.begin() + i);
			i--;
		}
	}
}
