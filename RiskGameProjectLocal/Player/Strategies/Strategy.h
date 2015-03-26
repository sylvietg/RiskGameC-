/*
 * Strategy.h
 *
 *  Created on: Mar 8, 2015
 *      Author: Emmanuel
 */

#ifndef PLAYER_STRATEGIES_STRATEGY_H_
#define PLAYER_STRATEGIES_STRATEGY_H_

#include <iostream>
#include <string.h>

#include "../../Map/Map.h"

class Strategy
{
public:
  Strategy ();
  virtual
  ~Strategy ();

  void setPlayer(std::string player);

  virtual char	decideAttack();
  std::string 	decideAttackingTerritory();
  std::string 	decideDefendingTerritory();
  char		decideKeepAttacking();

protected:
  std::string			mPlayer;
  std::vector<Territory*> 	mAttackList;
  Territory*			mAttacker;
  Territory*			mDefender;
};

#endif /* PLAYER_STRATEGIES_STRATEGY_H_ */
