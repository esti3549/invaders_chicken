#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Recources.h"

class PlayButton : public Button
{
public:
	PlayButton(sf::Vector2f location);
	~PlayButton() = default;
	virtual bool handleClick(sf::RenderWindow& window) override;
private:

};

