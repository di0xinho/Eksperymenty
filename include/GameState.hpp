#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.hpp"
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

	sf::Sprite _background;
	
	Player* player;
	Land* land;
	Platform* platform;
	
	int _gameState;

	int _score;
	int _lives;

	sf::Clock clock;

	sf::SoundBuffer _gameMusicBuffer;
	
	sf::Sound _gameMusic;
};