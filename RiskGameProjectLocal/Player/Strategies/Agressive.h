/*
 * Agressive.h
 *
 *  Created on: Mar 8, 2015
 *      Author: Emmanuel
 */

#ifndef PLAYER_STRATEGIES_AGRESSIVE_H_
#define PLAYER_STRATEGIES_AGRESSIVE_H_

#include "Strategy.h"

class Agressive : public Strategy
{
public:
  Agressive ();
  virtual
  ~Agressive ();

  char	 	decideAttack();
};

#endif /* PLAYER_STRATEGIES_AGRESSIVE_H_ */
