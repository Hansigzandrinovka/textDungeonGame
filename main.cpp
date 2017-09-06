//@author Hans Brown
//@date 8-30-2017
//@brief: handles display of the world, and taking in player inputs, communicating game information

#include <string>
#include <iostream>
#include "Tile.h"
#include "Entity.h"
#include "Map.h"

using namespace std;

static bool programDone = false;

//NTS: M 3 W E

static Entity* playerEntity = nullptr;
static int visibleAreaDimensions = 7; //dimensions of map  as X by X Tiled room
static Map* floorLayout = nullptr; //the entire map for the current floor of dungeon

//viewing is governed by expected size in tiles around character, with even values of xView or yView causing space above/left of character to be one less tile than bottom/right
int xView = 0;
int yView = 0;

void printTile(Tile targetTile)
{
	//TODO logic for printing tile
	if(targetTile.getOccupant() != nullptr)
	{
		std::cout << "E_";
	}
	else
	{
		std::cout << "__";
	}
}

void printDisplay(Entity playerEntity)
{
	if(xView <= 0 || yView <= 0)
	{
		//TODO throw exception
		std::cout << "Unable to print screen\n";
	}

	Tile*** visibleArea = floorLayout->getLayout(0,0);

	for(int y = 0; y < yView; y++) //iterate column-by-column thru visible view
	{
		for(int x = 0; x < xView; x++) //display row characters 1x1
		{
			Tile* possiblyTile = visibleArea[y][x];
			if(possiblyTile != nullptr)
			{
				printTile(*visibleArea[y][x]);
			}
			else
			{
				std::cout << "xx";
			}
		}
		std::cout << "\n"; //indent one line
	}
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

void initGame()
{
	//generate map
	yVisible = visibleAreaDimensions;
	floorLayout = new Map(visibleAreaDimensions, visibleAreaDimensions, 0);

	//populate dungeon with entities

	playerEntity = new Entity();
	try
	{
		placePlayer(playerEntity);
	}
	catch(Exception e)
	{
		return;
	}

	//init player view parameters

	xView = 3;
	yView = 3;
}

void cleanupGame()
{
	delete playerEntity;
	for(int i = 0; i < yView; i++)
	{
		for(int j = 0; j < xView; j++)
		{
			delete visibleArea[i][j];
		}
		delete[] visibleArea[i];
	}
	delete[] visibleArea;
}

int main()
{
    //initialize initial variables
    std::cout << "Game Begin\n";
    programDone = false;

    initGame();

    while(!programDone) //while the user still wants to play the game
    {
    	//provide UI
        printDisplay(*playerEntity);

        //wait for user interractions
		queryUserInput();

		//monsters react accordingly
		moveEnemies();
    }

    cleanupGame();

    std::cout << "Game Finished\n";
}
