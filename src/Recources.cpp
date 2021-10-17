#include "Recources.h"

Recources& Recources::getInstance()
{
	static Recources m_instance;
	return m_instance;
}
//---------------------------------------------------------------------
sf::Texture& Recources::getImg(std::string img)
{
	return m_imgs.find(img)->second;
}
//---------------------------------------------------------------------
std::unique_ptr<sf::Music>& Recources::getMusic(std::string music)
{
	return m_music.find(music)->second;
	
}
//---------------------------------------------------------------------
sf::SoundBuffer& Recources::getSound(std::string sound)
{
	return m_soundBuffer.find(sound)->second;
}
//---------------------------------------------------------------------
void Recources::setAndPlaySound(std::string sound, float vol)
{
	m_sound.setBuffer(m_soundBuffer[sound]);
	m_sound.setVolume(vol);
	m_sound.play();
}
//---------------------------------------------------------------------
void Recources::stopSound(std::string sound)
{
	m_sound.setBuffer(m_soundBuffer[sound]);
	m_sound.stop();
}
//---------------------------------------------------------------------
Recources::Recources()
{
	pushImgToMap();
	pushMusicToMap();
}
//---------------------------------------------------------------------
void Recources::pushImgToMap()
{
	auto img = sf::Texture();///////////

	img.loadFromFile("Background1.png");
	m_imgs.insert({ "Background1",img });

	img.loadFromFile("Background2.png");
	m_imgs.insert(std::make_pair("Background2", img));

	img.loadFromFile("BlueBigChicken.png");
	m_imgs.insert(std::make_pair("BlueBigChicken", img));

	img.loadFromFile("Bullet.png");
	m_imgs.insert(std::make_pair("Bullet", img));

	img.loadFromFile("BulletGift.png");
	m_imgs.insert(std::make_pair("BulletGift", img));

	img.loadFromFile("bomb.png");
	m_imgs.insert(std::make_pair("bomb", img));

	img.loadFromFile("boom.png");
	m_imgs.insert(std::make_pair("boom", img));

	img.loadFromFile("Egg.png");
	m_imgs.insert(std::make_pair("Egg", img));

	img.loadFromFile("HelpBackground.PNG");
	m_imgs.insert(std::make_pair("HelpBackground", img));

	img.loadFromFile("GreenChicken.PNG");
	m_imgs.insert(std::make_pair("GreenChicken", img));

	img.loadFromFile("Leg1.png");
	m_imgs.insert(std::make_pair("Leg1", img));

	img.loadFromFile("BrokenEgg.png");
	m_imgs.insert(std::make_pair("BrokenEgg", img));

	img.loadFromFile("Leg2.png");
	m_imgs.insert(std::make_pair("Leg2", img));

	img.loadFromFile("LifeGift.png");
	m_imgs.insert(std::make_pair("LifeGift", img));

	img.loadFromFile("MenuBackground.jpeg");
	m_imgs.insert(std::make_pair("MenuBackground", img));

	img.loadFromFile("OneLongBullet.png");
	m_imgs.insert(std::make_pair("OneLongBullet", img));

	img.loadFromFile("PurpleChicken.PNG");
	m_imgs.insert(std::make_pair("PurpleChicken", img));

	img.loadFromFile("StartButton.png");
	m_imgs.insert(std::make_pair("StartButton", img));

	img.loadFromFile("RedBigChicken.png");
	m_imgs.insert(std::make_pair("RedBigChicken", img));

	img.loadFromFile("RedChicken.PNG");
	m_imgs.insert(std::make_pair("RedChicken", img));

	img.loadFromFile("RedStone.png");
	m_imgs.insert(std::make_pair("RedStone", img));

	img.loadFromFile("SpaceShip.png");
	m_imgs.insert(std::make_pair("SpaceShip", img));

	img.loadFromFile("ProtectedShip.png");
	m_imgs.insert(std::make_pair("ProtectedShip", img));

	img.loadFromFile("Stone.PNG");
	m_imgs.insert(std::make_pair("Stone", img));

	img.loadFromFile("TowLongBullets.png");
	m_imgs.insert(std::make_pair("TowLongBullets", img));

	img.loadFromFile("HelpButton.png");
	m_imgs.insert(std::make_pair("HelpButton", img));

	img.loadFromFile("ExitButton.png");
	m_imgs.insert(std::make_pair("ExitButton", img));

	img.loadFromFile("RedHeart.png");
	m_imgs.insert(std::make_pair("RedHeart", img));

	img.loadFromFile("GameOver.PNG");
	m_imgs.insert(std::make_pair("GameOver", img));

	img.loadFromFile("Winner.PNG");
	m_imgs.insert(std::make_pair("Winner", img));

	m_font.loadFromFile("c:/Windows/Fonts/Forte.ttf");
}
//--------------------------------------------------------
void Recources::pushMusicToMap()
{
	m_music["melody"] = std::make_unique< sf::Music >();
	m_music["melody"]->openFromFile("melody.flac");
	m_music["melody"]->setVolume(40);

	m_soundBuffer["chewing"] = sf::SoundBuffer();
	m_soundBuffer["chewing"].loadFromFile("chewing.wav");

	m_soundBuffer["shoot"] = sf::SoundBuffer();
	m_soundBuffer["shoot"].loadFromFile("Shoot.wav");

	m_soundBuffer["Splat_egg"] = sf::SoundBuffer();
	m_soundBuffer["Splat_egg"].loadFromFile("Splat_egg.wav");

	m_soundBuffer["Protect"] = sf::SoundBuffer();
	m_soundBuffer["Protect"].loadFromFile("Protect.wav");

	m_soundBuffer["fail"] = sf::SoundBuffer();
	m_soundBuffer["fail"].loadFromFile("fail.wav");

	m_soundBuffer["clap"] = sf::SoundBuffer();
	m_soundBuffer["clap"].loadFromFile("clap.wav");
	
}
