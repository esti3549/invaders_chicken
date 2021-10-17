#include "DataDisplay.h"

DataDisplay::DataDisplay()
{
	for (int i = 0; i < 5; i++)
		m_lives.push_back(Recources::getInstance().getImg("RedHeart"));	

	m_printLevel = sf::Text("LEVEL   ", Recources::getInstance().m_font);
	setData(m_printLevel, { 1080 , 10 }, 22, sf::Color::White);
}
//------------------------------------------------------------------------------------
void DataDisplay::displayData(const int lives, const int score, const int level, sf::RenderWindow& window)
{
	sf::Sprite sprite;
	sf::Vector2f startPosition = { 20,10 };
	sprite.setTexture(m_lives[0]);
	for (int i = 0; i < lives; i++)
	{
		sprite.setPosition(startPosition);
		startPosition.x += (sprite.getGlobalBounds().width + 5);
		window.draw(sprite);
	}

	auto text = sf::Text(std::to_string(score), Recources::getInstance().m_font);
	setData(text, { 300,10 }, 22, sf::Color::White);
	window.draw(text);

	window.draw(m_printLevel); 
	text = sf::Text(std::to_string(level), Recources::getInstance().m_font);
	setData(text, { 1080 + m_printLevel.getGlobalBounds().width, 10 }, 22, sf::Color::White);
	window.draw(text);
}
//------------------------------------------------------------------------------------
void DataDisplay::setData(sf::Text& text, sf::Vector2f position, int size, sf::Color color)
{
	text.setFillColor(color);
	text.setPosition(position);
	text.setCharacterSize(size);
}
