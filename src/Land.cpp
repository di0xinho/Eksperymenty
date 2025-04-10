#include "Land.hpp"
#include "GameConfig.hpp"
#include <iostream>

Land::Land(GameDataRef data) : _data(data)
{
	sf::Sprite sprite(this->_data->assets.getTexture("Land"));
	sf::Sprite sprite2(this->_data->assets.getTexture("Land"));

	sprite.setPosition(0, this->_data->window.getSize().y - sprite.getLocalBounds().height);
	sprite2.setPosition(sprite.getLocalBounds().width, this->_data->window.getSize().y - sprite2.getLocalBounds().height);

	_landSprites.push_back(sprite);
	_landSprites.push_back(sprite2);
}

void Land::render()
{
	for (unsigned short int i = 0; i < _landSprites.size(); i++)
	{
		this->_data->window.draw(_landSprites.at(i));
	}
}

const std::vector<sf::Sprite>& Land::getSprites() const
{
	return _landSprites;
}
