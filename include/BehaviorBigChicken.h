#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colide.h"

class BehaviorBigChicken : public Colide
{
public:
	BehaviorBigChicken();
	~BehaviorBigChicken()=default;
	int getToDie();
	virtual bool colide() override;

protected:
	int m_counter = 5;
};
