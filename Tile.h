//@author Hans Brown
//@date 8-30-2017
//@brief: a floor location that users can navigate upon
#ifndef TILE_H
#define TILE_H

class Tile //object inherits from object<templated>
{
    public:
	//generates tile at given location
	//Tile(Tile *left, Tile *right, Tile *top, Tile *bot);
	//get the tiles around this tile
	//Tile* getLeftTile();
	//Tile* getRightTile();
	//Tile* getTopTile();
	//Tile* getBotTile();
	//returns occupying Entity, or nullptr if none
	//Entity* getOccupant();
	//bool Occupy(Entity* newOccupant);
	//void StopOccupying();

	private:
	//Tile* leftTile;
	//Tile* rightTile;
	//Tile* topTile;
	//Tile* botTile;
	//Entity* occupant;
};

#endif
