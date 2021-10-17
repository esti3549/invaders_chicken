#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Recources.h"
#include "Utilities.h"

class Object
{
public:
	Object(sf::Vector2f location);
	Object() = default;
	virtual ~Object()= default;
	void draw(sf::RenderWindow& window);//פונקציית ציור האובייקט
	float getWidthSprite() const;
	float getHightSprite() const;
	sf::Vector2f getPositionSprite() const;
	virtual void move(sf::Time deltaTime);
    void setColor();
	sf::Color getColor();
	sf::FloatRect getRectangle();
	//void setBoom();//////////////
	bool checkOutSideLimit();
	bool checkOutSideDownLimit();

protected:
	sf::Sprite m_sprite;
	
};
