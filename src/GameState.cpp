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

    /*_platforms.push_back(Platform(100.f, 500.f, 200.f, 20.f, sf::Color::Cyan));
    _platforms.push_back(Platform(400.f, 400.f, 200.f, 20.f, sf::Color::Black));
    _platforms.push_back(Platform(700.f, 300.f, 200.f, 20.f, sf::Color::Blue));
    _platforms.push_back(Platform(700.f, 500.f, 400.f, 20.f, sf::Color::Magenta));*/

    this->_data->assets.loadTexture("Background_Texture", BACKGROUND_TEXTURE);
    this->_data->assets.loadTexture("Land", LAND_TEXTURE);
    this->_data->assets.loadTexture("Player_Idle", PLAYER_IDLE);
    this->_data->assets.loadTexture("Player_Run_1", PLAYER_RUN_1);
    this->_data->assets.loadTexture("Player_Run_2", PLAYER_RUN_2);
    this->_data->assets.loadTexture("Player_Run_3", PLAYER_RUN_3);
    this->_data->assets.loadTexture("Player_Jump", PLAYER_JUMP);

    land = new Land(_data);
    player = new Player(_data);
    platform = new Platform(_data);
    
    _background.setTexture(this->_data->assets.getTexture("Background_Texture"));

    _gameState = GameStates::PLAYING;



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

    this->_data->window.draw(this->_background);

    land->render();
    platform->render();
    player->render();

    this->_data->window.display();
}
