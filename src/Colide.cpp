#include "..\include\Colide.h"
#include "SpaceShip.h"
Colide::Colide():m_toDie()
{
}

void Colide::colideWithSpaceship(SpaceShip& actor)
{
	Recources::getInstance().setAndPlaySound("shoot", 30);
	actor.setLife(-(actor.getLives()));
}

int Colide::getToDie()
{
	return m_toDie;
}

void Colide::setToDie(int num)
{
	m_toDie += num;
}
