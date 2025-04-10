#pragma once

// Tytu� gry
#define GAME_TITLE "Moja pierwsza gra platformowa"

// Wymiary okna gry
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Czcionki
#define ARIAL_FONT "../../../../Assets/Fonts/arial.ttf"
#define ROBOTO_FONT "../../../../Assets/Fonts/Roboto.ttf"

// Muzyka w tle
#define MENU_MUSIC "../../../../Assets/Music/menu-music.ogg"
#define GAME_MUSIC "../../../../Assets/Music/game-music.ogg"
#define MUSIC "../../../../Assets/Music/music.ogg"

// D�wi�ki i efekty d�wi�kowe
#define COIN_SOUND "../../../../Assets/Sounds/coin.ogg"
#define GAMEOVER_SOUND "../../../../Assets/Sounds/gameover.ogg"
#define JUMP_SOUND "../../../../Assets/Sounds/jump.ogg"
#define LEVEL_FAILED_SOUND "../../../../Assets/Sounds/level-failed.ogg"
#define LEVEL_PASSED_SOUND "../../../../Assets/Sounds/level-passed.ogg"
#define LIFE_COLLECT_SOUND "../../../../Assets/Sounds/life-collect.ogg"

// Tekstury
#define BACKGROUND_TEXTURE "../../../../Assets/Textures/background.png"
#define LAND_TEXTURE "../../../../Assets/Textures/land.png"
#define GAMEOVER_IMAGE "../../../../Assets/Textures/gameover.png"
#define PLAY_BUTTON "../../../../Assets/Textures/play_button.png"

// Tekstury g��wnej postaci
#define PLAYER_IDLE "../../../../Assets/Textures/idle.png"
#define PLAYER_RUN_1 "../../../../Assets/Textures/run1.png"
#define PLAYER_RUN_2 "../../../../Assets/Textures/run2.png"
#define PLAYER_RUN_3 "../../../../Assets/Textures/run3.png"
#define PLAYER_JUMP "../../../../Assets/Textures/jump.png"

// Tekstury coin�w
#define COIN_1 "../../../../Assets/Textures/coin1.png"
#define COIN_2 "../../../../Assets/Textures/coin2.png"
#define COIN_3 "../../../../Assets/Textures/coin3.png"
#define COIN_4 "../../../../Assets/Textures/coin4.png"
#define COIN_5 "../../../../Assets/Textures/coin5.png"
#define COIN_6 "../../../../Assets/Textures/coin6.png"
#define COIN_7 "../../../../Assets/Textures/coin7.png"
#define COIN_8 "../../../../Assets/Textures/coin8.png"
#define COIN_9 "../../../../Assets/Textures/coin9.png"
#define COIN_10 "../../../../Assets/Textures/coin10.png"
#define COIN_11 "../../../../Assets/Textures/coin11.png"
#define COIN_12 "../../../../Assets/Textures/coin12.png"
#define COIN_13 "../../../../Assets/Textures/coin13.png"
#define COIN_14 "../../../../Assets/Textures/coin14.png"

// Tekstury przeciwnika
#define ENEMY_1 "../../../../Assets/Textures/enemy1.png"
#define ENEMY_2 "../../../../Assets/Textures/enemy2.png"

// Inne zdefioniowane ustawienia
#define PLAYER_ANIMATION_DURATION 0.4f
#define GRAVITY 500.0f
#define SPEED 5.0f

#define PLAYER_STATE_STANDING 1
#define PLAYER_STATE_RUNNING 2
#define PLAYER_STATE_JUMPING 3

enum GameStates {
	PLAYING,
	GAMEOVER
};


