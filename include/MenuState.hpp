#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

class MenuState : public State {

public:
	MenuState(GameDataRef data);

	void Init();

	void handleInput();
	void update(float dt);
	void render(float dt);

private:
	GameDataRef _data;

	sf::Font font;
	sf::Text title;
	sf::Text instructions;

	sf::SoundBuffer _menuMusicBuffer;

	sf::Sound _menuMusic;
	

};