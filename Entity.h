//@author Hans Brown
//@date 8-30-2017
//@brief: an entity in-game that can move around, be attacked, and knows where it is

#ifndef ENT_H
#define ENT_H

class Tile; //Tile defined in "Tile.h"

enum DamageType {Slash,Pierce,Bludgeoning, Magic};

class Entity
{
    public:
	Entity(Tile* entitysTile);
	Tile* getSpace();
	void takeDamage(int amount, DamageType type);
	
	protected:
	Tile* currentTile;
};
#endif
