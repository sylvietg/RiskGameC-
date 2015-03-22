/*
 * Strategy.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: Emmanuel
 */

#include "Strategy.h"

Strategy::Strategy ()
{
  // TODO Auto-generated constructor stub

}

Strategy::~Strategy ()
{
  // TODO Auto-generated destructor stub
}

std::string
Strategy::decideAttackingTerritory ()
{
  std::string str;
  mAttacker = mAttackList.back();
  mAttackList.pop_back();
  return mAttacker->getName();
}

std::string
Strategy::decideDefendingTerritory ()
{

  Map* m = Map::getMapInstance();
  std::vector<Territory*> 	vt;
  vt = m->getTerritoriesByPlayer(mPlayer);
  bool owns;
  for(int i = 0; i < mAttacker->getNeighbors().size(); i++)
  {
      if(mAttacker->getNeighbors().at(i)->getAmountOfArmies() <= mAttacker->getAmountOfArmies()
	  && m->getTerritoryByName(mAttacker->getName())->getPlayerOwner() != m->getTerritoryByName(mAttacker->getNeighbors().at(i)->getName())->getPlayerOwner())
      {
	    return mAttacker->getNeighbors().at(i)->getName();
      }
  }
  for(int i = 0; i < mAttacker->getNeighbors().size(); i++)
  {
      if(m->getTerritoryByName(mAttacker->getName())->getPlayerOwner() != m->getTerritoryByName(mAttacker->getNeighbors().at(i)->getName())->getPlayerOwner())
	return mAttacker->getNeighbors().at(i)->getName();
  }
  return " ";
}

char
Strategy::decideKeepAttacking ()
{
  decideAttack();

  for(int i = 0; i < mAttackList.size(); i++)
  {
    if(mAttackList.at(i) == mAttacker)
      return 'y';
  }
  return 'n';
}

void
Strategy::setPlayer (std::string player)
{
  mPlayer = player;
}

char
Strategy::decideAttack ()
{
  return '3';
}
