#include "BehaviorSmallChicken.h"

BehaviorSmallChicken::BehaviorSmallChicken()
{
	m_toDie = 1;
}

bool BehaviorSmallChicken::colide()
{
	Recources::getInstance().setAndPlaySound("shoot", 30);
	m_toDie -= 1;
	return true;
}


