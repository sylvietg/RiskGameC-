/*
 * Agressive.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: Emmanuel
 */

#include "Agressive.h"

Agressive::Agressive ()
{
  // TODO Auto-generated constructor stub

}

Agressive::~Agressive ()
{
  // TODO Auto-generated destructor stub
}

char
Agressive::decideAttack ()
{
  Map *map = Map::getMapInstance();

   std::vector<Territory*> vt = map->getTerritoriesByPlayer(mPlayer);

   bool attack;
   bool hasEnemyNeighbor;

   mAttackList.clear();

   for(int i = 0; i < vt.size(); i++)
   {
       attack = false;
       hasEnemyNeighbor = false;
       for(int j = 0; j < vt.at(i)->getNeighbors().size(); j++)
       {
	  if(map->getTerritoryByName(vt.at(i)->getName())->getPlayerOwner() != map->getTerritoryByName(vt.at(i)->getNeighbors().at(j)->getName())->getPlayerOwner())
 	  {
 	      hasEnemyNeighbor = true;
 	      if( vt.at(i)->getNeighbors().at(j)->getAmountOfArmies() < vt.at(i)->getAmountOfArmies() && vt.at(i)->getAmountOfArmies() > 1)
 	      {
 		  attack = true;
 	      }
 	  }

       }
       if(attack && hasEnemyNeighbor)
 	mAttackList.push_back(vt.at(i));
   }
   if(mAttackList.size() > 0)
     return '1';
   else
     return '3';
}

