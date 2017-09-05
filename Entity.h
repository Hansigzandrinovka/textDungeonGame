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
	//attempts to move Entity to tile by magical warp-y means
	//fails if for some reason (terrain, etc.) Entity cannot occupy tile
	//returns true if travel was successful, false on failure
	bool goToSpace(Tile* newSpace);
	//performs logic to determine, without change of state, if Entity can/not occupy tile, returns true if can occupy
	const bool canOccupy(Tile* targetTile);
	void takeDamage(int amount, DamageType type);
	
	protected:
	Tile* currentTile;
};
#endif
