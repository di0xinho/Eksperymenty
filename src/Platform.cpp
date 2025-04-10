#include "Platform.hpp"
#include "GameConfig.hpp"

Platform::Platform(GameDataRef data) : _data(data)
{
	sf::RectangleShape platform1({ 200.0f, 20.0f });
	sf::RectangleShape platform2({ 200.0f, 20.0f });
	sf::RectangleShape platform3({ 200.0f, 20.0f });
	sf::RectangleShape platform4({ 200.0f, 20.0f });

	platform1.setPosition(200.0f, 200.0f);
	platform2.setPosition(480.0f, 180.0f);
	platform3.setPosition(720.0f, 200.0f);
	platform4.setPosition(1000.0f, 180.0f);
	
	platform1.setFillColor(sf::Color::Cyan);
	platform2.setFillColor(sf::Color::Blue);
	platform3.setFillColor(sf::Color::Red);
	platform4.setFillColor(sf::Color::Yellow);

	_platformShapes.push_back(platform1);
	_platformShapes.push_back(platform2);
	_platformShapes.push_back(platform3);
	_platformShapes.push_back(platform4);
}

void Platform::render()
{
	for (unsigned short int i = 0; i < _platformShapes.size(); i++)
	{
		this->_data->window.draw(_platformShapes.at(i));
	}
}

const std::vector<sf::RectangleShape>& Platform::getShapes() const
{
	return _platformShapes;
}