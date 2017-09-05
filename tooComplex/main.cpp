//@author Hans Brown
//@date 8-30-2017
//@brief: handles display of the world, and taking in player inputs, communicating game information

#include <string>
#include <iostream>
#include "Entity.h"
#include "Tile.h"

using namespace std;

static bool programDone = false;

void printMap()
{
	//to implement
}

void queryUserInput()
{
	//to implement
	programDone = true;
}

void moveEnemies()
{
	//to implement
}

int main()
{
    //initialize initial variables
    std::cout << "Game Begin\n";
    programDone = false;

    while(!programDone) //while the user still wants to play the game
    {
        printMap();
		queryUserInput();

		moveEnemies();
    }

    std::cout << "Game Finished\n";
}
