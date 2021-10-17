#include "HelpButton.h"

HelpButton::HelpButton(sf::Vector2f location) :Button(location)
{
	m_sprite.setTexture(Recources::getInstance().getImg("HelpButton"));
}
//---------------------------------------------------------------------------------
bool HelpButton::handleClick(sf::RenderWindow& window)
{
	sf::RenderWindow h_window(sf::VideoMode(WIDTH_OF_H_WINDOW, HEIGHT_OF_H_WINDOW), "Help Screen");
	sf::Sprite sprite;
	sprite.setTexture(Recources::getInstance().getImg("HelpBackground"));

	while (h_window.isOpen())
	{
		h_window.clear();//ניקוי החלון
		h_window.draw(sprite);
		h_window.display();
		if (auto  event = sf::Event{}; h_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				h_window.close();
				break;
			}
			default:
				break;
			}
		}
	}
	return false;
}
