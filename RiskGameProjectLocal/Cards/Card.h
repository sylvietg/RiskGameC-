#ifndef CARD_H_
#define CARD_H_

#include <ctime>
#include <cstdlib>
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
	void setTypeOfArmyStr(std::string typeStr);

	// Others
	int generateTypeOfArmy();
	std::string getTypeOfArmyStr();
	

private:
	int typeOfArmy; //2: Infantry 3: Cavalry 5: Artillery
	std::string typeStr;
	std::string territoryName;
};

#endif /* CARD_H_ */
