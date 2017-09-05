//@author Hans Brown
//@date 9-1-2017
//@brief: a collection of tiles that represent a single cohesive room for the purpose of spawning and pathfinding
#ifndef ROOM_H
#define ROOM_H

#include "Tile.h"

class Room //
{
    public:
	Room(int xDim, int yDim);
	~Room();
	Tile* getTopLeft();

	void connectLeft(Room* left);
	void connectRight(Room* right);
	void connectDown(Room* bot);
	void connectUp(Room* top);

	void disconnectAll();

	private:
	Room* leftRoom;
	Room* rightRoom;
	Room* topRoom;
	Room* botRoom;
	Tile* topLeftTile;
	int xSize;
	int ySize;
	void deleteTileRec(Tile* givenTile);
};

#endif
