#pragma once
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "GameConfig.hpp"

class ScoreManager {
public:
    ScoreManager(GameDataRef data);
    ~ScoreManager();

    void updateScore(int points);

    void render();

private:
    GameDataRef _data;
    sf::Text _scoreText;
};

	
