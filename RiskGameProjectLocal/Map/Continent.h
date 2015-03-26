/*
 * Continent.h
 *
 *  Created on: Jan 30, 2015
 *      Author: mateus
 */

#ifndef CONTINENT_H_
#define CONTINENT_H_

#include <vector>
#include "Territory.h"
#include "../Player/Player.h"
#include "Observable.h"

class Continent : public Observable
{

public:
	// constructors
	Continent();

	Continent(std::string name, std::vector<Territory*> territories);

	// destructor
	virtual ~Continent();

	// getter
	std::vector<Territory*> getTerritories();

	std::string getName();

	std::string getColor();

	// setter
	void setTerritories(std::vector<Territory*> territories);

	void setName(std::string name);

	void setColor(std::string color);

	// other methods
	void printMyTerritories();

	Territory* getTerritoryByName(std::string territory);

	void addNewTerritory(Territory* territory);

	void removeTerritory(Territory* territory); // removes from the continent, don't delete


private:

	std::vector<Territory*> territories;
	std::string name;
	std::string color;

};

#endif /* CONTINENT_H_ */
