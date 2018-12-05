// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <SFML/Graphics.hpp>

#define PLAYER_IDLE 0
#define PLAYER_RUN 1
#define BARREL 2
#define BARREL_BROKEN 3

struct Textures
{
	sf::Texture* myTexture = new sf::Texture;
	int myFrames = 0,
		myColumns = 0,
		myRows = 0;
};

template<typename T> inline void PtrDelete(T *aPtr)
{
	aPtr = nullptr;
	delete[](aPtr);
}

#endif //PCH_H
