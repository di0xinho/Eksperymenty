#include "Game.hpp"
#include "MenuState.hpp"

#include <stdlib.h>
#include <time.h>

Game::Game(int width, int height, std::string title)
{
	srand(time(NULL));

	_data->window.create(sf::VideoMode(width, height), title);
	_data->stateMachine.AddState(StateRef(new MenuState(this->_data)));

	this->run();
}

void Game::run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen())
	{
		this->_data->stateMachine.ProcessStateChanges();

		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->_data->stateMachine.GetActiveState()->handleInput();
			this->_data->stateMachine.GetActiveState()->update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->_data->stateMachine.GetActiveState()->render(interpolation);
	}
}

	
