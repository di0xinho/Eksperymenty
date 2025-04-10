#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameConfig.hpp"
#include "Game.hpp"

#include <vector>

class Player
{
public:
	Player(GameDataRef data);
	~Player();

	void render();

	void animate(float dt);

	void update(float dt);

	void setPosition(float x, float y);

	void run();

	void jump();

	const sf::Sprite& getSprite() const;

private:
	GameDataRef _data;

	sf::Sprite _playerSprite;
	std::vector<sf::Texture> _animationFrames;

	unsigned int _animationIterator;

	sf::Clock _clock;

	sf::Clock _movementClock;

	int _playerState;
};