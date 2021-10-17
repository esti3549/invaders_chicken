#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Recources.h"

class ExitButton : public Button
{
public:
	ExitButton(sf::Vector2f location);
	~ExitButton() = default;
	virtual bool handleClick(sf::RenderWindow& window) override;
private:

};
