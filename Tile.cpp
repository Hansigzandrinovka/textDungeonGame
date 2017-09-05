//@author Hans Brown
//@date 8-30-2017
//@brief: see Tile.h

#include "Tile.h"

using namespace std;

Tile::Tile()
{
	leftTile = nullptr;
	rightTile = nullptr;
	topTile = nullptr;
	botTile = nullptr;
}

Entity* Tile::getOccupant()
{
	return nullptr;
}

void Tile::connectLeft(Tile* tile)
{
	if(leftTile == nullptr)
		leftTile = tile;
}

void Tile::connectRight(Tile* tile)
{
	if(rightTile == nullptr)
		rightTile = tile;
}

void Tile::connectUp(Tile* tile)
{
	if(topTile == nullptr)
		topTile = tile;
}

void Tile::connectDown(Tile* tile)
{
	if(botTile == nullptr)
		botTile = tile;
}

void Tile::disconnectAll()
{
	if(leftTile != nullptr)
	{
		leftTile->rightTile = nullptr;
	}
	if(rightTile != nullptr)
	{
		rightTile->leftTile = nullptr;
	}
	if(topTile != nullptr)
	{
		topTile->botTile = nullptr;
	}
	if(botTile != nullptr)
	{
		botTile->topTile = nullptr;
	}
}