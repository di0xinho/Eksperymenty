#include "GameOverState.hpp"
#include "GameState.hpp"
#include "GameConfig.hpp"
#include <iostream>

GameOverState::GameOverState(GameDataRef data) : _data(data) {}

void GameOverState::Init() {

    this->_data->assets.loadFont("Roboto", ROBOTO_FONT);

    this->_data->soundManager.loadSound("gameover", GAMEOVER_SOUND);

    title.setFont(this->_data->assets.getFont("Roboto"));
    title.setString("Koniec gry");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(200.0f, 100.0f);

    instructions.setFont(font);
    instructions.setString("Nacisnij klawisz 'ENTER', aby zaczac jeszcze raz");
    instructions.setCharacterSize(25);
    instructions.setFillColor(sf::Color::White);
    instructions.setPosition(220.0f, 300.0f);

    this->_data->soundManager.playSound("gameover");
}

void GameOverState::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        this->_data->stateMachine.AddState(StateRef(new GameState(_data)), true);
    }
}

void GameOverState::update(float dt) {}

void GameOverState::render(float dt) {

    this->_data->window.clear(sf::Color::Black);

    this->_data->window.draw(this->title);
    this->_data->window.draw(this->instructions);

    this->_data->window.display();
}