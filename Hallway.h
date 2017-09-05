//@author Hans Brown
//@date 9-1-2017
//@brief: a connecting line between two Rooms, typically 1 tile wide or long depending on orientation
#ifndef HALL_H
#define HALL_H

#include "Tile.h"

enum hall_orientation {left_right,up_down};

class Hallway
{
    public:
	Hallway(Room* room1, Room* room2, hall_orientation newOrientation);
	~Hallway();
	Tile* getTile1();
	Tile* getTile2();
	Room* getRoom1();
	Room* getRoom2();

	void connectLeft(Room* left);
	void connectRight(Room* right);
	void connectDown(Room* bot);
	void connectUp(Room* top);

	void disconnectAll();

	private:
	hall_orientation orientation;
	Room* room1;
	Room* room2;
	Tile* tile1;
	Tile* tile2;
	int length
};

#endif
