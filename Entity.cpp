//@author Hans Brown
//@date 8-30-2017
//@brief: see Entity.h

#include "Entity.h"
#include "Tile.h"

using namespace std;

Entity::Entity()
{
	currentTile = nullptr;
}

Tile* Entity::getSpace()
{
	return currentTile;
}

void Entity::takeDamage(int amount, DamageType type)
{
	//to be extended by children
}

bool Entity::goToSpace(Tile* newSpace)
{
	if(!canOccupy(newSpace))
	{
		return false;
	}
	if(currentTile != nullptr)
	{
		currentTile->StopOccupying();
	}
	if(!newSpace->Occupy(this))
	{
		return false;
	}
	currentTile = newSpace;
	return true;
}

const bool Entity::canOccupy(Tile* targetTile)
{
	if(targetTile == nullptr || (targetTile->getOccupant() != nullptr))
		return false;

	//room for additional conditionals

	return true;
}