// CrossActionGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <chrono>
#include <time.h>
#include <thread>
#include <sys/timeb.h>

timeb myTb;

int main()
{
	Game tempGame;
	bool tempRunFlag = true;
	
	auto tempNs = std::chrono::high_resolution_clock::now();
	long tempPreviousTime = 
		std::chrono::duration_cast<std::chrono::nanoseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count(); //Gets previous time
	double tempNsPerTick = 1000000000 / 60.0f; //Nanoseconds per tick

	int tempTicks = 0;
	int tempFrames = 0;

	long tempLastTimer = myTb.millitm;
	double tempDelta = 0;


	sf::RenderWindow tempWindow(sf::VideoMode(1280, 720), "Everlast");
	tempGame.Initialize();

	while (tempRunFlag && tempWindow.isOpen()) 
	{
		tempNs = std::chrono::high_resolution_clock::now(); //Gets current time in nanoseconds

		long tempNow = 
			std::chrono::duration_cast<std::chrono::nanoseconds>
			(std::chrono::system_clock::now().time_since_epoch()).count(); 
		tempDelta += (tempNow - tempPreviousTime) / tempNsPerTick;
		tempPreviousTime = tempNow;

		sf::Event tempEvent;
		while (tempWindow.pollEvent(tempEvent))
		{
			if (tempEvent.type == sf::Event::Closed) { tempWindow.close(); } //Makes sure the game closes when X is pressed.
		}

		while (tempDelta >= 1) 
		{
			tempTicks++;
			tempGame.Update(tempDelta);
			tempDelta--;
		}

		try 
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2)); //Sleep for 2ms
		}
		catch (int e) 
		{
			std::cout << "Error #" << e << std::endl;
		}

		tempFrames++; //Updates frames

		tempWindow.clear();
		tempGame.Render(tempWindow);
		tempWindow.display();

		if (myTb.millitm - tempLastTimer >= 1000) {
			tempLastTimer += 1000;
			std::cout << "Ticks: " + std::to_string(tempTicks) + "   Frames: " + std::to_string(tempFrames) + "   Delta: " + std::to_string(tempDelta) << std::endl;
			tempTicks = 0;
			tempFrames = 0;
		}
	}
}