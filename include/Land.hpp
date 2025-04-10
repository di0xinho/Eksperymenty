#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

class Land
{
public:
	Land(GameDataRef data);

	void render();

	const std::vector<sf::Sprite>& getSprites() const;

private:
	GameDataRef _data;

	std::vector<sf::Sprite>_landSprites;

};