//@author Hans Brown
//@date 9-5-2017
//@brief: see Map.h
#ifndef MAP_H
#define MAP_H

Map::Map(int xBounds, int yBounds, int seed)
{
	xSize = xBounds;
	ySize = yBounds;
	room = nullptr;
}

Map::generateMap(int seed)
{
	//TODO: more complex room generation
	floor = new Tile**[ySize];
	for(int i = 0; i < yBounds; i++)
	{
		room[i] = new Tile*[xSize];
		for(int j = 0; j < xBounds; j++)
		{
			room[i][j] = new Tile();
		}
	}
}
Map::~Map()
{
	for(int i = 0; i < yBounds; i++)
	{
		for(int j = 0; j < xBounds; j++)
		{
			delete room[i][j];
		}
		delete[] room[i];
	}
	delete[] room;
}
Tile*** Map::getLayout(out int xDim, out int yDim)
{
	xDim = xSize;
	yDim = ySize;
	return floor;
}
	
void Map::placePlayer(Entity playerEntity)
{
	int xCoord = xSize / 2;
	int yCoord = ySize / 2;
	Tile* targetTile = floor[yCoord][xCoord];
	//try to place player on a tile in floor, starting at middle tile and traveling right/down
	for(int i = ySize / 2; i < ySize; i++)
	{
		for(int j = xSize / 2; j < xSize && floor[i][j] != nullptr; j++)
		{
			//when we find location for player, we are finished
			if(playerEntity.goToSpace(floor[i][j]))
				return;
		}
	}
}

	private:
  Tile*** room;
  int xSize;
  int ySize;
};

#endif