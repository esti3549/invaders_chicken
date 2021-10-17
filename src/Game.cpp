#include "Game.h"

Game::Game() : m_actor({ 540,650 })
{
}
//----------------------------------------------------------
void Game::run(sf::RenderWindow& window)
{
	bool result = false;
	
	auto filelevel = std::string("Level1.txt");
	int numOfLevel = 1;
	while (std::ifstream(filelevel))
	{
		Level level(numOfLevel);
		result = level.run(m_actor, window, filelevel);

		if (result)
			numOfLevel++;
		else
		{
			Recources::getInstance().getMusic("melody")->stop();
			Recources::getInstance().setAndPlaySound("fail");
			resultGame(window, "GameOver");
			break;
		}
		filelevel = std::string("Level") + std::to_string(numOfLevel) + std::string(".txt");
	}
	if (result)
	{
		Recources::getInstance().getMusic("melody")->stop();
		Recources::getInstance().setAndPlaySound("clap");
		resultGame(window, "Winner");
	}
	Recources::getInstance().getMusic("melody")->stop();
}
//----------------------------------------------------------
void Game::resultGame(sf::RenderWindow& window, std::string screen)
{
	window.clear();
	sf::Sprite sprite;
	sprite.setTexture(Recources::getInstance().getImg(screen));
	window.draw(sprite);
	window.display();

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(4s);
	
	Recources::getInstance().stopSound("Winner");
	Recources::getInstance().stopSound("GameOver");
}
