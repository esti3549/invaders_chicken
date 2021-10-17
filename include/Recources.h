#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>

class Recources
{
public:
	~Recources() = default;
	static Recources& getInstance();

	sf::Texture& getImg(std::string img);
	std::unique_ptr<sf::Music>& getMusic(std::string music);
	sf::SoundBuffer& getSound(std::string sound);///
	void setAndPlaySound(std::string sound, float vol = 100);
	void stopSound(std::string sound);

	sf::Font  m_font;
	sf::Sound m_sound;

protected:
	std::map<std::string, sf::Texture> m_imgs;
	std::map<std::string, std::unique_ptr<sf::Music>> m_music;
	std::map<std::string, sf::SoundBuffer> m_soundBuffer;

	Recources(); //c-tor
	Recources(const Recources& other) = default; //copy c-tor
	Recources& operator=(const Recources& other) = default;
	void pushImgToMap();//פונקצייה שמכניסה את התמונות למפה
	void pushMusicToMap();
};

