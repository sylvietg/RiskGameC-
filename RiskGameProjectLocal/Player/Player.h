#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"


class Player
{
public:

	Player();
	Player(int n);
	Player(std::string name);
	/*int getOrder();
	Continent getContinent();
	Card getCard();
	void setOrder();*/
std::string getColor();
	void setColor(std::string color);
	void setName(std::string n);
	std::string getName();
	int getNumber();
	void setNArmy(int a);
	int getNArmy();
	void incArmy();
	void decArmyToPlace();
	void winTerritory();
	void loseTerritory();
	int getNTerritory();
//	void addCard();
	int getNCard();
	void setNCard(int i);
	void setOrder(int o);
	bool getHasNewTerritory();
	void setHasNewTerritory(bool b);
	int getListCards(int index);
	void setListCards(int i, int j, int k);
	void setNReinforcement(int n);
	int getNReinforcement();

  void
  setNumber (int number)
  {
    mNumber = number;
  }

protected:
  std::string name;

private:
	std::string color;
	int mNumber;

	int nCard;
	int nArmy;
	int nTerritory;
	int nContinent;
	int numOfCard;
	int nReinforcement;
	int nWin;

	bool hasNewTerritory;

//	std::vector<Continent*> Player::listContinents; //New
//	std::vector<Territory*> Player::listTerritories;
	int listCards[3];
	
};
#endif /* PLAYER_H_ */
