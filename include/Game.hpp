#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "SoundManager.hpp"

struct GameData {
	sf::RenderWindow window;
	StateMachine stateMachine;
	AssetManager assets;
	InputManager input;
	SoundManager soundManager;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game {
public: 
	Game(int width, int height, std::string title);

private:
	const float dt = 1.0f / 60.0f;
	sf::Clock _clock;

	GameDataRef _data = std::make_shared<GameData>();

	void run();
};