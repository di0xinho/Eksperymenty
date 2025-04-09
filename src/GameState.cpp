#pragma once

#include "GameState.hpp"
#include "GameConfig.hpp"
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
    _gameMusic.setLoop(true);
    _gameMusic.play();

    _score = 0;

   /* if (!font.loadFromFile(ROBOTO_FONT)) {
        throw std::runtime_error("Nie mozna zaladowac czcionki");
    }*/
}

void GameState::handleInput() {

    // SprawdŸ wciœniête klawisze i wywo³aj przypisane komendy
    for (auto key : { sf::Keyboard::Left, sf::Keyboard::Right }) {
        if (sf::Keyboard::isKeyPressed(key)) {
            auto command = this->_data->input.GetCommand(key); // Pobierz przypisan¹ komendê
            if (command) {
                command->execute(); // Wykonaj komendê
            }
        }
    }

}

void GameState::update(float dt) {}

void GameState::render(float dt) {

    this->_data->window.clear(sf::Color::Black);
    this->_data->window.display();
}
