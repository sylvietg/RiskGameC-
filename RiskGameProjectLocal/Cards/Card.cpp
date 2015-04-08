#include "Card.h"

// Constructor
Card::Card(std::string name)
{
	std::cout << "Territory Name, Type of Army \n";
	territoryName = name;
	typeOfArmy = 0;
}

// Copy constructor
Card::Card(const Card* otherCard)
{
	territoryName = otherCard->territoryName;
	typeOfArmy = otherCard->typeOfArmy;
}

// Getters
std::string Card::getTerritoryName()
{
	return territoryName;
}

int Card::getTypeOfArmy()
{
	return typeOfArmy;
}

// Setters
void Card::setTerritoryName(std::string name)
{
	territoryName = name;
}

void Card::setTypeOfArmy(int type)
{
	typeOfArmy = type;
}

// Others
int Card::generateTypeOfArmy()
{
	std::cout << "Choose randomly a country and a type of army. \n";
	return (rand() % 3) + 1;
}

std::string Card::getTypeOfArmyStr()
{
	if (typeOfArmy == 1)
		return "Infantry";
	else if (typeOfArmy == 2)
		return "Cavalry";
	else if (typeOfArmy == 3)
		return "Artillery";
	else
		return "Wild Card";
}
