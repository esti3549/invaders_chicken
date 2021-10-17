#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Recources.h"
#include "Utilities.h"

class HelpButton : public Button
{
public:
	HelpButton(sf::Vector2f location);
	~HelpButton() = default;
	virtual bool handleClick(sf::RenderWindow& window) override;
private:

};
