#include "Fortification.h"

Fortification::Fortification()
{
	std::cout << "Fortification phase!\n\n";
}

Fortification::Fortification(Player* p)
{
	std::cout << "Fortification phase!\n\n";
	map = Map::getMapInstance();
	mCurrent = p;
	migrate = 0;
}

void Fortification::move(std::string origin, std::string destination, int order)
{
	map->getTerritoryByName(destination)->setAmountOfArmies(order);
	//Fix or add remove method
	map->getTerritoryByName(origin)->setAmountOfArmies(order);
}

void Fortification::selectDestination(std::string origin, std::string destination, int order)
{
	if (map->getTerritoryByName(destination)->getPlayerOwner()->getNumber() == order)
	{
		std::cout << "How many Territory do you want to migrate 1-" << migrate << "?\n";
		int ans;
		std::cin >> ans;
		move(origin, destination, ans);
	}
}

void Fortification::selectOrigin(std::string origin, int order)
{
	if (map->getTerritoryByName(origin)->getAmountOfArmies() > 2)
	{
		std::cout << "Army can be migrated.\n\n";
		migrate = (map->getTerritoryByName(origin)->getAmountOfArmies()) - 2;
		std::cout << "Please choose a destination.\n\n";
		std::string d;
		std::cin >> d;
		selectDestination(origin, d, order);
	}
	else
		std::cout << "Army cannot be migrated.\n\n";
}

void Fortification::fortify(int order)
{
	std::cout << "Please choose an origin.\n\n";
	std::string o;
	std::cin >> o;
	selectOrigin(o, order);

}
