#include "MenuState.hpp"
#include "GameConfig.hpp"
#include <iostream>

MenuState::MenuState(GameDataRef data) : _data(data) {}

void MenuState::Init() {

    if (!_menuMusicBuffer.loadFromFile(MENU_MUSIC)) {
        throw std::runtime_error("Nie mozna zaladowac muzyki");
    }
    
    _menuMusic.setBuffer(_menuMusicBuffer);
    _menuMusic.setLoop(true);
    _menuMusic.play();

    if (!font.loadFromFile(ROBOTO_FONT)) {
        throw std::runtime_error("Nie mozna zaladowac czcionki");
    }

	title.setFont(font);
    title.setString("Moja gra platformowa");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(200.0f, 100.0f);

    instructions.setFont(font);
    instructions.setString("Przycisnij ENTER, by przejsc do rozgrywki");
    instructions.setCharacterSize(25);
    instructions.setFillColor(sf::Color::White);
    instructions.setPosition(220.0f, 300.0f);
}

void MenuState::handleInput()
{
}

void MenuState::update(float dt) {}

void MenuState::render(float dt) {

    this->_data->window.clear(sf::Color::Black);

    this->_data->window.draw(this->title);
    this->_data->window.draw(this->instructions);

    this->_data->window.display();
}