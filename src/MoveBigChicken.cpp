#include "MoveBigChicken.h"

MoveBigChicken::MoveBigChicken(): m_downIterations(6150), m_upIterations(BIG_CHICKEN_ITERATION),
m_leftIterations(BIG_CHICKEN_ITERATION), m_rightIterations(BIG_CHICKEN_ITERATION)
{
}

void MoveBigChicken::move(sf::Time deltaTime, sf::Sprite& sprite)
{
	sprite.setTexture(Recources::getInstance().getImg("RedBigChicken"));
	if (m_downIterations > 0 && (m_downIterations <= 6150 || m_downIterations <= BIG_CHICKEN_ITERATION))
	{
		m_direction = calculateDirection(Down);
		calculateRoad(m_direction, 50);
		sprite.move(m_direction * deltaTime.asSeconds());
		m_downIterations--;
	}
	if (m_downIterations == 0)
	{
		if (m_upIterations > 0 && m_upIterations <= BIG_CHICKEN_ITERATION)
		{
			m_direction = calculateDirection(Up);
			calculateRoad(m_direction, 50);
			sprite.move(m_direction * deltaTime.asSeconds());
			m_upIterations--;
		}
	}
	if (m_upIterations == 0)
	{
		if (m_leftIterations > 0 && m_leftIterations <= BIG_CHICKEN_ITERATION)
		{
			m_direction = calculateDirection(Left);
			calculateRoad(m_direction, 100);
			sprite.move(m_direction * deltaTime.asSeconds());
			m_leftIterations--;
		}

	}
	if (m_leftIterations == 0)
	{
		if (m_rightIterations > 0 && m_rightIterations <= BIG_CHICKEN_ITERATION)
		{
			m_direction = calculateDirection(Right);
			calculateRoad(m_direction, 100);
			sprite.move(m_direction * deltaTime.asSeconds());
			m_rightIterations--;
		}
	}
	if (m_rightIterations == 0)
		m_downIterations = m_upIterations = m_leftIterations = m_rightIterations = BIG_CHICKEN_ITERATION;
}

int MoveBigChicken::getWidth()
{
	return WIDTH_IMG_BIG_CHICKEN;
}

int MoveBigChicken::getHight()
{
	return HIGHT_IMG_BIG_CHICKEN;
}
