//@author Hans Brown
//@date 8-30-2017
//@brief: an entity in-game that can move around, be attacked, and knows where it is

#ifndef ENT_H
#define ENT_H
#include "Tile.h"

class Entity
{
    public:
	Entity(Tile* entitysTile);
	//Tile* getSpace();
	
	protected:
	//void takeDamage(int amount);
	//Tile* currentTile;
};
#endif
