#pragma once
#include <SFML/Graphics.hpp>
#include "Recources.h"

class DataDisplay
{
public:
	DataDisplay();
	~DataDisplay() = default;
	void displayData(const int lives, const int score, const int level, sf::RenderWindow& window);

protected:
	//sf::Sprite m_lives;
	std::vector<sf::Texture> m_lives;
	//sf::Text m_printScore;
	sf::Text m_printLevel;

	void setData(sf::Text& text, sf::Vector2f position, int size, sf::Color color);
};

