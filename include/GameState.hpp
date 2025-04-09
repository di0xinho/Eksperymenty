#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"

class GameState : public State {
public:

	GameState(GameDataRef data);

	void Init();

	void handleInput();
	void update(float dt);
	void render(float dt);

private:

	GameDataRef _data;
	sf::RectangleShape player;

	int _score;
	int _lives;

	sf::Clock clock;

	sf::SoundBuffer _gameMusicBuffer;
	
	sf::Sound _gameMusic;
};