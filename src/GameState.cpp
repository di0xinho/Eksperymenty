#pragma once

#include "GameState.hpp"
#include "GameConfig.hpp"
#include "PauseState.hpp"
#include "MoveLeftCommand.hpp"
#include "MoveRightCommand.hpp"
#include <iostream>

GameState::GameState(GameDataRef data) : _data(data) {}

void GameState::Init()
{
	this->_data->input.BindKey(sf::Keyboard::Left, std::make_shared<MoveLeftCommand>());
	this->_data->input.BindKey(sf::Keyboard::Right, std::make_shared<MoveRightCommand>());

    if (!_gameMusicBuffer.loadFromFile(GAME_MUSIC)) {
        throw std::runtime_error("Nie mozna zaladowac muzyki");
    }

    _gameMusic.setBuffer(_gameMusicBuffer);
    _gameMusic.setVolume(100.f);
    _gameMusic.setLoop(true);
    _gameMusic.play();

    _score = 0;
    _lives = 3;


   /* if (!font.loadFromFile(ROBOTO_FONT)) {
        throw std::runtime_error("Nie mozna zaladowac czcionki");
    }*/
}

void GameState::resume() {
    _gameMusic.setVolume(100.f);
}

void GameState::pause() {
    _gameMusic.setVolume(50.f);
}

void GameState::handleInput() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        
        this->_data->stateMachine.AddState(StateRef(new PauseState(_data)), false);
    }

    // Sprawd� wci�ni�te klawisze i wywo�aj przypisane komendy
    for (auto key : { sf::Keyboard::Left, sf::Keyboard::Right }) {
        if (sf::Keyboard::isKeyPressed(key)) {
            auto command = this->_data->input.GetCommand(key); // Pobierz przypisan� komend�
            if (command) {
                command->execute(); // Wykonaj komend�
            }
        }
    }

}

void GameState::update(float dt) {}

void GameState::render(float dt) {

    this->_data->window.clear(sf::Color::Black);
    this->_data->window.display();
}
