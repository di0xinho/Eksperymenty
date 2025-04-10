#include "ScoreManager.hpp"
#include <string>

ScoreManager::ScoreManager(GameDataRef data) : _data(data) {
    
	_scoreText.setFont(this->_data->assets.getFont("Roboto"));
	_scoreText.setCharacterSize(36);
    _scoreText.setFillColor(sf::Color::White);
    _scoreText.setString("0");
	_scoreText.setPosition(sf::Vector2f(30, 30));
}

void ScoreManager::updateScore(int points)
{
	_scoreText.setString(std::to_string(points));
}

void ScoreManager::render() {
	_data->window.draw(_scoreText);
}