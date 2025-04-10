#include "Player.hpp"

Player::Player(GameDataRef data) : _data(data) {

	_animationIterator = 0;

	_animationFrames.push_back(this->_data->assets.getTexture("Player_Run_1"));
	_animationFrames.push_back(this->_data->assets.getTexture("Player_Run_2"));
	_animationFrames.push_back(this->_data->assets.getTexture("Player_Run_3"));
	
	_playerSprite.setTexture(_animationFrames.at(_animationIterator));

	_playerSprite.setScale(2, 2);

	_playerSprite.setPosition((_data->window.getSize().x / 4) - (_playerSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) + (_playerSprite.getGlobalBounds().height / 2));
	
	_playerState = PLAYER_STATE_STANDING;

	sf::Vector2f origin = sf::Vector2f(_playerSprite.getGlobalBounds().width / 2, _playerSprite.getGlobalBounds().height / 2);

	_playerSprite.setOrigin(origin);
}

Player::~Player(){}

void Player::render() {
	_data->window.draw(_playerSprite);
}

void Player::animate(float dt) {

	if (_clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION_DURATION / _animationFrames.size())
	{
		if (_animationIterator < _animationFrames.size() - 1)
		{
			_animationIterator++;
		}
		else
		{
			_animationIterator = 0;
		}

		_playerSprite.setTexture(_animationFrames.at(_animationIterator));

		_clock.restart();
	}
}

void Player::update(float dt) {

	if (PLAYER_STATE_JUMPING == _playerState) {
		_playerSprite.move(0.0f, GRAVITY * dt);
	}
	else if (PLAYER_STATE_RUNNING == _playerState) {
		_playerSprite.move(0.0f, GRAVITY * dt);
	}
}

void Player::setPosition(float x, float y) {
	_playerSprite.setPosition(x, y);
}

void Player::jump() {
	std::cout << "Skacze" << std::endl;
	_movementClock.restart();
	_playerState = PLAYER_STATE_JUMPING;
}

void Player::run() {
	std::cout << "Biegne"<<std::endl;
	_movementClock.restart();
	_playerState = PLAYER_STATE_RUNNING;
}

const sf::Sprite& Player::getSprite() const
{
	return _playerSprite;
}