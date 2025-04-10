#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "Collision.hpp"
#include "ScoreManager.hpp"
#include "State.hpp"
#include "Player.hpp"
#include "Land.hpp"
#include "Platform.hpp"

class GameState : public State {
public:

	GameState(GameDataRef data);

	void Init();

	void handleInput();
	void update(float dt);
	void render(float dt);

	void pause() override;
	void resume() override;

private:

	GameDataRef _data;
	ScoreManager* scoreManager;
	Collision collision;
	

	sf::Sprite _background;
	
	Player* player;
	Land* land;
	Platform* platform;

	int _gameState;

	int _score;
	int _lives;

	sf::Clock clock;
};