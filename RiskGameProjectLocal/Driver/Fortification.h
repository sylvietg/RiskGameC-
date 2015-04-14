#pragma once

#include "../Map/Map.h"
#include "../Player/Player.h"

class Fortification
{
public:
	Fortification();
	Fortification(Player* p);
	void selectOrigin(std::string o, int order);
	void selectDestination(std::string o, std::string d, int order);
	void move(std::string origin, std::string destination, int order);
	void fortify(int i);

private:
	Map* map;
	Player *mCurrent;
	int migrate;
	Territory origin;
	Territory destination;
};
