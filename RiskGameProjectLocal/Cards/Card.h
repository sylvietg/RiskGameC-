#ifndef CARD_H_
#define CARD_H_

#include <math.h>
#include <string>
#include <iostream>
#include <stdlib.h>

class Card
{
public:
	// Constructor
	Card(std::string name);

	// Copy Constructor
	Card(const Card* otherCard);

	// Getters
	std::string getTerritoryName();
	int getTypeOfArmy();

	// Setters
	void setTerritoryName(std::string name);
	void setTypeOfArmy(int type);
	
	// Others
	int generateTypeOfArmy();
	std::string getTypeOfArmyStr();

private:
	int typeOfArmy; //0: Wild card 1: Infantry 2: Cavalry 3: Artillery
	std::string territoryName;
};

#endif /* CARD_H_ */
