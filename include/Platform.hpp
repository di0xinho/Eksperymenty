#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"

class Platform
{
public:
    Platform(GameDataRef data);

    void render(); // Funkcja rysuj�ca platform� na ekranie

    const std::vector<sf::RectangleShape>& getShapes() const;

private:
    GameDataRef _data;
    std::vector<sf::RectangleShape> _platformShapes;
};