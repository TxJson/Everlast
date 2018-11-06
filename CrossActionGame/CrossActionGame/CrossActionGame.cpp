// CrossActionGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	int tempVelX = 0,
		tempVelY = 0;

	sf::Vector2f tempPosition = shape.getPosition();

	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				tempPosition.y -= tempVelY;
				tempVelY++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				tempPosition.y += tempVelY;
				tempVelY++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				tempPosition.x -= tempVelX;
				tempVelX++;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				tempPosition.x += tempVelX;
				tempVelX++;
			}

			shape.setPosition(tempPosition);
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file