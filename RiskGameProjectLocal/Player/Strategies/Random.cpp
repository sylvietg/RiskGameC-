/*
 * Random.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: Emmanuel
 */

#include "Random.h"

Random::Random ()
{
  // TODO Auto-generated constructor stub

}

Random::~Random ()
{
  // TODO Auto-generated destructor stub
}

char
Random::decideAttack ()
{
  Map *map = Map::getMapInstance();

  std::vector<Territory*> vt = map->getTerritoriesByPlayer(mPlayer);

  bool attack;
  bool hasEnemyNeighbor;

  srand (time(NULL));

  mAttackList.clear();

  for(int i = 0; i < vt.size(); i++)
  {
      attack = false;
      hasEnemyNeighbor = false;
      for(int j = 0; j < vt.at(i)->getNeighbors().size(); j++)
      {
	  if(vt.at(i)->getNeighbors().at(j)->getPlayerOwner()->getName() != mPlayer)
	  {
	      hasEnemyNeighbor = true;
	      if(vt.at(i)->getAmountOfArmies() > 1)
	      {
		  attack = true;
	      }
	  }

      }
      if(attack && hasEnemyNeighbor)
	mAttackList.push_back(vt.at(i));
  }


  int choice = rand() % 3 + 1;
  switch(choice)
  {
    case 1:
      return '1';
    case 2:
      return '2';
    case 3:
      return '3';
  }
}
