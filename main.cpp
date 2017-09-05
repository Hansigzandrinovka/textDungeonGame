//@author Hans Brown
//@date 8-30-2017
//@brief: handles display of the world, and taking in player inputs, communicating game information

#include <string>
#include <iostream>
#include "Tile.h"
#include "Entity.h"

using namespace std;

static bool programDone = false;
//visibleArea is a [y][x] dimension array composed of all Tile objects in the game world, size-governed by yVisible and xVisible
//visibleArea[0][0] corresponds to top-left room of current floor
static Tile*** visibleArea = nullptr;
int yVisible = 0;
int xVisible = 0;
static Entity* playerEntity = nullptr;
static int visibleAreaDimensions = 7;

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
		std::cout << "Unable to print screen\n";
	}
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

//generate the tiles to populate the map
void generateTiles(Tile*** map, int xSize, int ySize)
{
	for(int i = 0; i < ySize; i++)
	{
		for(int j = 0; j < xSize; j++)
		{
			Tile* generatedTile = new Tile();
			map[i][j] = generatedTile;
			if(i > 0) //if there is a tile above this tile
				generatedTile->connectUp(map[i - 1][j]);
			if(j > 0) //if there is a tile left of this
				generatedTile->connectLeft(map[i][j - 1]);
		}
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
	xVisible = visibleAreaDimensions;
	visibleArea = new Tile**[yVisible]; //an array of [yVisible] pointers
	for(int i = 0; i < yVisible; i++) //each index has xVisible pointers
	{
		visibleArea[i] = new Tile*[xVisible];
	}

	generateTiles(visibleArea, yVisible, xVisible);

	//populate dungeon with entities

	playerEntity = new Entity(nullptr);

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
