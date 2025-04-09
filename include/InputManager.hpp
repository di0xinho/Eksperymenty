#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include "Command.hpp"

class InputManager {
public:
    // Mapowanie klawisza na komendê
    void BindKey(sf::Keyboard::Key key, std::shared_ptr<Command> command);

    // Pobranie komendy przypisanej do klawisza
    std::shared_ptr<Command> GetCommand(sf::Keyboard::Key key) const;

private:
    std::map<sf::Keyboard::Key, std::shared_ptr<Command>> commandMap;
};