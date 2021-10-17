#include "Menu.h"

Menu::Menu():m_sprite(Recources::getInstance().getImg("MenuBackground"))
{
	m_menu.emplace_back(std::make_unique<PlayButton>( sf::Vector2f(900, 440)) );
	m_menu.emplace_back(std::make_unique<HelpButton>( sf::Vector2f(780, 550)) );
	m_menu.emplace_back(std::make_unique<ExitButton>( sf::Vector2f(660, 680)) );
	
}
//-------------------------------------------------------------------------
void Menu::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite); 
	for(const auto& button : m_menu)
		button->draw(window);
}
//-------------------------------------------------------------------------
void Menu::run(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		draw(window);//הצגת התפריט
		window.display();
		if (auto  event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();
				exit(EXIT_SUCCESS);
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				for (const auto& button : m_menu)
				{
					if (isContain(event.mouseButton, window, *button))//אם הלחיצה הייתה על אחד הכפתורים
						if (button->handleClick(window))
							return;
				}
				break;
			}
			default:
				break;
			}
		}
	}
}
//-------------------------------------------------------------------------
bool Menu::isContain(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window, Button& button)
{
	return (button.getSprite().getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })));
}
