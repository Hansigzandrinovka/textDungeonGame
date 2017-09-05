//@author Hans Brown
//@date 9-1-2017
//@brief: see Room.h

#include "Room.h"
#include <queue>

using namespace std;

Room::Room(int xDim, int yDim)
{
	xSize = xDim;
	ySize = yDim;

	Tile* topMostTile = new Tile();
	Tile* leftMostTile = topMostTile;
	//create initial row
	for(int i = 1; i < xDim; i++)
	{
		leftMostTile->connectLeft(new Tile());
		leftMostTile = leftMostTile->getLeftTile();
	}
	//stack rows on top of it as needed
	for(int i = 1; i < yDim; i++) //for each y layer after 0th
	{
		topMostTile->connectUp(new Tile());
		topMostTile = topMostTile->getTopTile();
		leftMostTile = topMostTile;
		for(int j = 1; j < yDim; j++) //at each step on y layer, generate a new right x Tile
		{
			leftMostTile->connectLeft(new Tile());
			leftMostTile = leftMostTile->getLeftTile();
		}
	}
	//after stacking rows, leftMostTile is left most tile of topMostTile, which is top most tile of room
}

Tile* Room::getTopLeft()
{
	return topLeftTile;
}

Room::~Room()
{
	Tile* deleteTile = topLeftTile;
	Tile* nextCol = topLeftTile;
	for(int i = 0; i < xSize; i++)
	{
		Tile* nextRow = nextCol;
		nextCol = nextCol->getRightTile();
		//rightIterator
		for(int j = 0; j < ySize; j++)
		{
			nextRow = nextRow->getBotTile();
			deleteTile->disconnectAll();
			delete deleteTile;
			deleteTile = nextRow;
		}
		deleteTile = nextCol;
	}
}

void Room::connectLeft(Room* tile)
{
	if(leftRoom == nullptr)
	{
		leftRoom = tile;
	}
}

void Room::connectRight(Room* tile)
{
	if(rightRoom == nullptr)
	{
		rightRoom = tile;
	}
}

void Room::connectUp(Room* tile)
{
	if(topRoom == nullptr)
	{
		topRoom = tile;
	}
}

void Room::connectDown(Room* tile)
{
	if(botRoom == nullptr)
	{
		botRoom = tile;
	}
}

void Room::disconnectAll()
{
	if(leftRoom != nullptr)
	{
		leftRoom->rightRoom = nullptr;
	}
	if(rightRoom != nullptr)
	{
		rightRoom->leftRoom = nullptr;
	}
	if(topRoom != nullptr)
	{
		topRoom->botRoom = nullptr;
	}
	if(botRoom != nullptr)
	{
		botRoom->topRoom = nullptr;
	}
}