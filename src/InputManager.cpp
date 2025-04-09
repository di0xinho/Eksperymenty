#include "InputManager.hpp"

void InputManager::BindKey(sf::Keyboard::Key key, std::shared_ptr<Command> command) {
    commandMap[key] = command;
}

std::shared_ptr<Command> InputManager::GetCommand(sf::Keyboard::Key key) const {
    auto it = commandMap.find(key);
    if (it != commandMap.end()) {
        return it->second;
    }
    return nullptr; // Jeœli brak przypisanej komendy
}