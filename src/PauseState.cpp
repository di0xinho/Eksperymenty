#include "PauseState.hpp"
#include "GameState.hpp"
#include "GameConfig.hpp"
#include <iostream>

PauseState::PauseState(GameDataRef data) : _data(data) {}

void PauseState::Init() {

    if (!font.loadFromFile(ROBOTO_FONT)) {
        throw std::runtime_error("Nie mozna zaladowac czcionki");
    }

    title.setFont(font);
    title.setString("Gra wstrzymana");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(200.0f, 100.0f);

    instructions.setFont(font);
    instructions.setString("Nacisnij klawisz 'U', aby powrocic do rozgrywki");
    instructions.setCharacterSize(25);
    instructions.setFillColor(sf::Color::White);
    instructions.setPosition(220.0f, 300.0f);

    std::cout << this->_data->stateMachine.GetActiveState()<<std::endl;
}

void PauseState::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
        this->_data->stateMachine.RemoveState();
    }
}

void PauseState::update(float dt) {}

void PauseState::render(float dt) {

    this->_data->window.clear(sf::Color::Black);

    this->_data->window.draw(this->title);
    this->_data->window.draw(this->instructions);

    this->_data->window.display();
}