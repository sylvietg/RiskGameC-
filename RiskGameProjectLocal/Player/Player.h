#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include "../Cards/Deck.h"
#include "../Map/Observable.h"


class Player : public Observable
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
	void setTurnState(bool state);
	std::string getName();
	int getNumber();
	void setNArmy(int a);
	int getNArmy();
	bool getTurnState();
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
	void setNReinforcement(int n);
	int getNReinforcement();

	Deck* getPDeck();


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
	bool turnState;

	Deck *pDeck; //New
	
};
#endif /* PLAYER_H_ */
