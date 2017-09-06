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

	private:
	void generateMap(int seed);
  Tile*** floor;
  int xSize;
  int ySize;
};

#endif