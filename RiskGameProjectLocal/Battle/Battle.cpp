/*
 * Battle.cpp
 *
 *  Created on: Feb 5, 2015
 *      Author: Emmanuel
 */

#include "Battle.h"

Battle::Battle ()
{
  mAttacker = NULL;
  mDeffender = NULL;

  srand (time(NULL));

}

Battle::~Battle ()
{
  // TODO Auto-generated destructor stub
}

void
Battle::RunBattle (bool allIn, Player* player)
{
  bool keepAttacking = true;
  bool setupOK = SetupBattle(player);


  while(keepAttacking && setupOK)
  {
      mAttackersDice.clear();
      mDeffendersDice.clear();
      if(mAttacker->getAmountOfArmies() < min_armies_to_attack)
      {
	std::cout<<"You don't have enough armies to attack"<<std::endl;
	return;
      }

      if(player->getName() == "AI")
       {
	 RollDices(true);
       }
      else
	RollDices(allIn);

      for(int i = 0; i < mDeffendersDice.size(); i++)
      {
	  if(mAttackersDice.at(i) > mDeffendersDice.at(i))
	  {
	      mDeffender->setAmountOfArmies(mDeffender->getAmountOfArmies()-1);
	  }
	  else
	  {
	      mAttacker->setAmountOfArmies(mAttacker->getAmountOfArmies()-1);
	  }
      }

      //PRINT CURRENT GAME

      if(mDeffender->getAmountOfArmies() == 0)
      {
	  int newArmies;
	  std::cout<<"Attackers Won! Distribute your armies!"<<std::endl<<"How many armies will you place in your new territory?"<<std::endl;
	  if(player->getName() == "AI")
	   {
	     AIPlayer *AI = (AIPlayer*)player;

	     newArmies = 1;
	     std::cout<<newArmies<<std::endl;
	   }
	  else
	    std::cin>>newArmies;
	  if(newArmies > mAttackersDice.size())
	  {
	      newArmies = mAttackersDice.size();
	  }
	  if(newArmies > mAttacker->getAmountOfArmies() - 1)
	  {
	      newArmies = mAttacker->getAmountOfArmies() - 1;
	  }
	  mDeffender->setAmountOfArmies(newArmies);
	  mAttacker->setAmountOfArmies(mAttacker->getAmountOfArmies() - newArmies);
	  mDeffender->setPlayerOwner(mAttacker->getPlayerOwner());
	  std::cout<<mDeffender->getName()<<" is now owned by: "<<mDeffender->getPlayerOwner()->getName()<<std::endl;
	  return;
      }
      else if(!allIn)
      {
	  char choice;



	  std::cout<<"Keep Attacking? (y/n)"<<std::endl;
	  if(player->getName() == "AI")
	   {
	     AIPlayer *AI = (AIPlayer*)player;

	     choice = AI->decideKeepAttacking();
	     std::cout<<choice<<std::endl;
	   }
	  else
	    std::cin>>choice;
	  if(choice == 'n')
	  {
	      keepAttacking = false;
	  }
	  else
	  {
	      keepAttacking = true;
	  }
      }
  }

}

void
Battle::setDeffender (Territory* deffender)
{
  mDeffender = deffender;
}

void
Battle::RollDices (bool allin)
{
  int atDice;
  if(!allin){
    std::cout<<"How many dice do you wish to roll?"<<std::endl;
    std::cin>>atDice;
  }
  else
  {
      atDice = 3;
  }
  if(atDice > max_attack_dices)
  {
    atDice = max_attack_dices;
  }
  if(atDice > mAttacker->getAmountOfArmies() - 1)
  {
    atDice = mAttacker->getAmountOfArmies() - 1;
  }
  int dfDice;
  dfDice = mDeffender->getAmountOfArmies();
  if(dfDice > max_defense_dices)
  {
    dfDice = max_defense_dices;
  }
  if(dfDice > atDice)
  {
      dfDice = atDice;
  }

  //rand

  for(int i = 0; i < atDice; i++)
  {
      mAttackersDice.push_back(rand() % 6 + 1);
  }
  for(int i = 0; i < dfDice; i++)
  {
      mDeffendersDice.push_back(rand() % 6 + 1);
  }

  std::sort(mAttackersDice.begin(), mAttackersDice.end(), std::greater<int>());
  std::sort(mDeffendersDice.begin(), mDeffendersDice.end(), std::greater<int>());

  std::cout<<std::endl<< "Attackers Dice: "<<std::endl;
  for(int i = 0; i < atDice; i++)
    {
        std::cout<<mAttackersDice.at(i)<<" ";
    }
    std::cout<<std::endl<< "Defenders Dice: "<<std::endl;
    for(int i = 0; i < dfDice; i++)
    {
        std::cout<<mDeffendersDice.at(i)<<" ";
    }
    std::cout<<std::endl;
}


bool
Battle::SetupBattle (Player* player)
{
    mMap = Map::getMapInstance();
    std::string at, dt;

    if(player->getName() == "AI")
    {
      AIPlayer *AI = (AIPlayer*)player;

      at = AI->decideAttackingTerritory();
      std::cout<<at<<std::endl;
    }
    else{
      std::cin.clear();
      std::cin.get();
      std::cout<<"Choose Attacking Territory:" <<std::endl;
      getline(std::cin, at);
    }
    if(mMap->getTerritoryByName(at)->getPlayerOwner() == player)
    {
        setAttacker(mMap->getTerritoryByName(at));
    }
    else
    {
        std::cout<<"This territory doesn't belong to you!"<<std::endl;
        return false;
    }


    if(player->getName() == "AI")
     {
       AIPlayer *AI = (AIPlayer*)player;

       dt = AI->decideDefendingTerritory();
       std::cout<<dt<<std::endl;
     }
    else{
      std::cout<<"Choose Defending Territory:" <<std::endl;
      getline(std::cin, dt);
    }
    if(mMap->getTerritoryByName(dt)->getPlayerOwner() != player)
    {
      setDeffender(mMap->getTerritoryByName(dt));
    }
    else
    {
      std::cout<<"You can't attack a territory owned by yourself!"<<std::endl;
      return false;
    }
    if(!mAttacker->isNeighbor(mDeffender))
    {
      std::cout<<"These territories are not neighbors!"<<std::endl;
      return false;
    }
    return true;
}

void
Battle::setAttacker (Territory* attacker)
{
  mAttacker = attacker;
}


