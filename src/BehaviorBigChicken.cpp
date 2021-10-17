#include "BehaviorBigChicken.h"

BehaviorBigChicken::BehaviorBigChicken()
{
	m_toDie = 25;
}

int BehaviorBigChicken::getToDie()
{
	return m_toDie;
}

bool BehaviorBigChicken::colide()
{
	Recources::getInstance().setAndPlaySound("shoot", 30);
	m_toDie -= 1;
	return true;
}

