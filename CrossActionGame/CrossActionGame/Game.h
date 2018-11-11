#ifndef GAME_H
#define GAME_H

#define VERSION 0.01
#define AUTHOR "Pontuz Klasson"
#define REPOSITORY "https://github.com/Tuz1e/Everlast"

#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void LoadContent();
	void Update(float &aDeltaTime);
	void Render(sf::RenderWindow &aWindow);
	void LateRender(sf::RenderWindow &aWindow);

	Player myPlayer;
};

#endif