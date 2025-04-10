#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include "Command.hpp"

class InputManager {
public:

    bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

    sf::Vector2i GetMousePosition(sf::RenderWindow& window);

    // Mapowanie klawisza na komendê
    void BindKey(sf::Keyboard::Key key, std::shared_ptr<Command> command);

    // Pobranie komendy przypisanej do klawisza
    std::shared_ptr<Command> GetCommand(sf::Keyboard::Key key) const;

private:
    std::map<sf::Keyboard::Key, std::shared_ptr<Command>> commandMap;
};