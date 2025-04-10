#include "InputManager.hpp"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (playButtonRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}

	return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}

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