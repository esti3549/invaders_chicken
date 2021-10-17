#include "Object.h"

Object::Object(sf::Vector2f location)
{
	m_sprite.setPosition(location);
}
//-------------------------------------------------
void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//-------------------------------------------------
float Object::getWidthSprite() const
{
	return (m_sprite.getGlobalBounds().width);
}
//-------------------------------------------------
float Object::getHightSprite() const
{
	return (m_sprite.getGlobalBounds().height);
}
//-------------------------------------------------
sf::Vector2f Object::getPositionSprite() const
{
	return m_sprite.getPosition();
}
void Object::move(sf::Time deltaTime)
{
}
//-------------------------------------------------
//void Object::move(sf::Time deltaTime)
//{
//	//////////////////////virtual=0!!!!!!!!!!!
//}
//-------------------------------------------------
void Object::setColor()
{
	m_sprite.setColor(sf::Color::Transparent);
}
//-------------------------------------------------
sf::Color Object::getColor()
{
	return m_sprite.getColor();
}
//-------------------------------------------------
sf::FloatRect Object::getRectangle()
{
	return m_sprite.getGlobalBounds();
}
//-------------------------------------------------
bool Object::checkOutSideLimit()
{
	return (m_sprite.getPosition().y < 0);
	
}
//-------------------------------------------------
bool Object::checkOutSideDownLimit()
{
	return (m_sprite.getPosition().y > HEIGHT_OF_WINDOW);
}
