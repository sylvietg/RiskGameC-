/*
 * Defensive.h
 *
 *  Created on: Mar 8, 2015
 *      Author: Emmanuel
 */

#ifndef PLAYER_STRATEGIES_DEFENSIVE_H_
#define PLAYER_STRATEGIES_DEFENSIVE_H_

#include "Strategy.h"

class Defensive : public Strategy
{
public:
  Defensive ();
  virtual
  ~Defensive ();

  char	 	decideAttack();

};

#endif /* PLAYER_STRATEGIES_DEFENSIVE_H_ */
