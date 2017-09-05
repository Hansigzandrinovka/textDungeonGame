//@author Hans Brown
//@date 8-30-2017
//@brief: see Entity.h

#include "Entity.h"

using namespace std;

Entity::Entity(Tile* entitysTile)
{
	currentTile = entitysTile;
}

Tile* Entity::getSpace()
{
	return currentTile;
}

void Entity::takeDamage(int amount, DamageType type)
{
	//to be extended by children
}