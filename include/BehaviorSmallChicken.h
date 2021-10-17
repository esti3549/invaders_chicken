#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Colide.h"
 

class BehaviorSmallChicken: public Colide
{
public:
	BehaviorSmallChicken();
	virtual ~BehaviorSmallChicken()=default;
	virtual bool colide() override;

protected:
};