#pragma once

#include "GameState.hpp"
#include "GameConfig.hpp"
#include "GameOverState.hpp"
#include "MoveLeftCommand.hpp"
#include "MoveRightCommand.hpp"
#include <iostream>

GameState::GameState(GameDataRef data) : _data(data) {}

void GameState::Init()
{
	this->_data->input.BindKey(sf::Keyboard::Left, std::make_shared<MoveLeftCommand>());
	this->_data->input.BindKey(sf::Keyboard::Right, std::make_shared<MoveRightCommand>());

    this->_data->soundManager.loadSound("jump", JUMP_SOUND);
    this->_data->soundManager.loadSound("coin", COIN_SOUND);
    this->_data->soundManager.loadSound("level-passed", LEVEL_PASSED_SOUND);
    this->_data->soundManager.loadSound("level-failed", LEVEL_FAILED_SOUND);
    this->_data->soundManager.loadSound("life-collect", LIFE_COLLECT_SOUND);
    
    this->_data->soundManager.loadMusic("game", GAME_MUSIC);
    this->_data->soundManager.setMusicLoop("game", true);
    this->_data->soundManager.playMusic("game");

    _score = 0;
    _lives = 3;

    this->_data->assets.loadFont("Roboto", ROBOTO_FONT);

    scoreManager = new ScoreManager(_data);
    _score = 0;
    scoreManager->updateScore(_score);

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
}

void GameState::resume() {
    this->_data->soundManager.setVolume("game", 100.f);
}

void GameState::pause() {
    this->_data->soundManager.setVolume("game", 25.f);
}

void GameState::handleInput() {

    if (GameStates::GAMEOVER != _gameState)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {

            this->_data->stateMachine.AddState(StateRef(new PauseState(_data)), false);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
            _gameState = GameStates::GAMEOVER;
        }
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

void GameState::update(float dt) {

    if (GameStates::GAMEOVER != _gameState)
    {
        player->animate(dt);
    }

    if (GameStates::PLAYING == _gameState)
    {
        
        player->update(dt);

        std::vector<sf::Sprite> landSprites = land->getSprites();
        std::vector<sf::RectangleShape> platformShapes = platform->getShapes();

        for (int i = 0; i < landSprites.size(); i++)
        {
            /*if (collision.CheckSpriteCollision(player->getSprite(), 0.7f, landSprites.at(i), 1.0f))
            {
                player->setPosition(player->getSprite().getPosition().x, landSprites.at(i).getGlobalBounds().height);
            }*/
            if (collision.CheckSpriteCollision(player->getSprite(), landSprites.at(i)))
            {
                player->setPosition(player->getSprite().getPosition().x, landSprites.at(i).getGlobalBounds().height);
            }
        }


        if (GameStates::GAMEOVER == _gameState)
        {
            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
            {
                this->_data->soundManager.stopAllMusic();
                this->_data->stateMachine.AddState(StateRef(new GameOverState(_data)), true);
            }
        }
    }

}

void GameState::render(float dt) {

    this->_data->window.clear(sf::Color::Black);

    this->_data->window.draw(this->_background);

    land->render();
    platform->render();
    player->render();
    scoreManager->render();

    this->_data->window.display();
}
