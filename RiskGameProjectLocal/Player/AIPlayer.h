/*
 * AIPlayer.h
 *
 *  Created on: Mar 8, 2015
 *      Author: Emmanuel
 */

#ifndef PLAYER_AIPLAYER_H_
#define PLAYER_AIPLAYER_H_

#include "Player.h"
#include "Strategies/Strategy.h"
#include "Strategies/Agressive.h"
#include "Strategies/Defensive.h"
#include "Strategies/Random.h"

class AIPlayer : public Player
{
public:
  AIPlayer (std::string name, int n);
  virtual
  ~AIPlayer ();

  void 		setStrategy(Strategy* newStrategy);

  char	 	decideAttack();
  std::string 	decideAttackingTerritory();
  std::string 	decideDefendingTerritory();
  char		decideKeepAttacking();

private:

  Strategy*	mStrategy;

};

#endif /* PLAYER_AIPLAYER_H_ */
