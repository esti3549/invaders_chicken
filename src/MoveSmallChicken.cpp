#include "MoveSmallChicken.h"


MoveSmallChicken::MoveSmallChicken()
{
}

void MoveSmallChicken::move(sf::Time deltaTime, sf::Sprite& sprite)
{
	sprite.setTexture(Recources::getInstance().getImg("BlueBigChicken"));
	if (m_iterations == 0)
	{
		int randomDirection = rand() % 2;
		m_iterations = ITERATION;
		switch (randomDirection)
		{
		case 0://right
			m_direction = { 1,0 };
			calculateRoad(m_direction, SMALL_CHICKEN_SPEED);
			if (checkLimitR((m_direction * deltaTime.asSeconds()) + sprite.getPosition(), sprite))
				sprite.move(m_direction * deltaTime.asSeconds());
			break;
		case 1://left
			m_direction = { -1,0 };
			calculateRoad(m_direction, SMALL_CHICKEN_SPEED);
			if (checkLimitL((m_direction * deltaTime.asSeconds()) + sprite.getPosition()))
				sprite.move(m_direction * deltaTime.asSeconds());
			break;
		default:
			break;
		}
	}
	m_iterations--;
	if (checkLimitR((m_direction * deltaTime.asSeconds()) + sprite.getPosition(), sprite) &&
		checkLimitL((m_direction * deltaTime.asSeconds()) + sprite.getPosition()))
		sprite.move(m_direction * deltaTime.asSeconds());
}

int MoveSmallChicken::getWidth()
{
	return WIDTH_IMG_SMALL_CHICKEN;
}

int MoveSmallChicken::getHight()
{
	return HIGHT_IMG_SMALL_CHICKEN;
}
