#ifndef GAME_H
#define GAME_H

#define VERSION 0.01
#define AUTHOR "Pontuz Klasson"
#define REPOSITORY "https://github.com/Tuz1e/Everlast"

#include "WorldManager.h"

enum GameState
{
	MENU,
	GAME,
	PAUSE
};

class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void LoadContent(sf::RenderWindow &aWindow);
	void Update(float &aDeltaTime);
	void Render(sf::RenderWindow &aWindow);
	void LateRender(sf::RenderWindow &aWindow);

	GameState myGState;
	WorldManager myWM;
	//Player *myPlayer;
	//EnemyManager myEM;
	//CollisionManager myCM;
	//ObjectManager myObjM;
};

#endif