//@author Hans Brown
//@date 9-5-2017
//@brief: a static object that maintains view of every tile in the game, and provides access to the layout while masking con/destruction of the array
#ifndef MAP_H
#define MAP_H

#include "Tile.h"

class Map
{
    public:
	Map(int xBounds, int yBounds, int seed);
	~Map();
	Tile*** getLayout(out int xDim, out int yDim);
	
	void placePlayer(Entity playerEntity);
	Tile* getTile(int xCoord, int yCoord)

	private:
	void generateMap(int seed);
	//floor is a [y][x] dimension array composed of all Tile objects in the game world, size-governed by ySize and xSize
	//floor[0][0] corresponds to top-left tile of current floor
	Tile*** floor;
	int xSize;
	int ySize;
};

#endif