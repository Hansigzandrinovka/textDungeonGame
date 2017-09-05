//@author Hans Brown
//@date 8-30-2017
//@brief: a floor location that users can navigate upon
#ifndef TILE_H
#define TILE_H

class Entity; //Entity defined in "Entity.h"

class Tile //object inherits from object<templated>
{
    public:
    Tile();

	//get the tiles around this tile
	Tile* getLeftTile();
	Tile* getRightTile();
	Tile* getTopTile();
	Tile* getBotTile();

	//returns occupying Entity, or nullptr if none
	Entity* getOccupant();
	//bool Occupy(Entity* newOccupant);
	//void StopOccupying();

	//connection methods make 2-way connection between this and given tile
	void connectLeft(Tile* left);
	void connectRight(Tile* right);
	void connectUp(Tile* top);
	void connectDown(Tile* down);

	//disconnection methods remove the 2-way connection established by connect, allowing safe deletion
	void disconnectAll(); //disconnects at all boundaries to tile
	//after disconnecting all connections, tile will be safe for deletion

	private:
	Tile* leftTile;
	Tile* rightTile;
	Tile* topTile;
	Tile* botTile;
	//Entity* occupant;
	//Item* loot
};

#endif
