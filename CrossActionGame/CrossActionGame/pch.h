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
#include <string>

#define PLAYER_IDLE	0
#define PLAYER_WALK 1
#define PLAYER_ATTACK 2
#define PLAYER_HIT 3
#define SKELETON_IDLE 4
#define SKELETON_WALK 5
#define SKELETON_ATTACK 6
#define SKELETON_HIT 7

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

//void ErrorMessage(const std::string &aClass, const int &aLine, const std::string &aMessage)
//{
//	printf("ERROR @Class: %s, Line: %i\n ERROR Message: %s\n", aClass, aLine, aMessage);
//}

#endif //PCH_H
