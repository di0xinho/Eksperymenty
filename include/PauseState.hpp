#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

class PauseState : public State {

public:
	PauseState(GameDataRef data);

	void Init();

	void handleInput();
	void update(float dt);
	void render(float dt);

private:
	GameDataRef _data;

	sf::Font font;
	sf::Text title;
	sf::Text instructions;
};