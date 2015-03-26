/*
 * Random.h
 *
 *  Created on: Mar 8, 2015
 *      Author: Emmanuel
 */

#ifndef PLAYER_STRATEGIES_RANDOM_H_
#define PLAYER_STRATEGIES_RANDOM_H_

#include "Strategy.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Random : public Strategy
{
public:
  Random ();
  virtual
  ~Random ();

  char	 	decideAttack();
};

#endif /* PLAYER_STRATEGIES_RANDOM_H_ */
