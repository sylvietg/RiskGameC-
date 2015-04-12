#include "Player.h"

Player::Player()
{
	//order = 0;
	mNumber = 0;
	name = "";
	turnState = false;
	nCard = 0;
	nTerritory = 0;
	nContinent = 0;
	nArmy = 0;
	nReinforcement = 0;
	nWin = 0;
	this->color = "gray"; // default
	pDeck = new PlayerDeck;
}

Player::Player(std::string color)
{
	this->color = color;
	pDeck = new PlayerDeck;
}
Player::Player(int n)
{
	mNumber = n;
	name = "";
	turnState = false;
  	nCard = 0;
  	nTerritory = 0;
  	nContinent = 0;
  	nArmy = 0;
  	nReinforcement = 0;
  	nWin = 0;
	this->color = "green"; // default
	pDeck = new PlayerDeck;
}


std::string Player::getColor()
{
	return this->color;
}

void Player::setName(std::string n)
{
	name = n;

	notify();
}

void Player::setTurnState(bool state)
{
	this->turnState = state;

	notify();
}

void Player::setColor(std::string color)
{
	this->color = color;

	notify();
}
std::string Player::getName()
{
	return name;
}

int
Player::getNumber()
{
  return mNumber;
}

bool Player::getTurnState()
{
	return this->turnState;
}

void Player::setNArmy(int a)
{
	nArmy = a;
}

int Player::getNArmy()
{
	// Local variables
	int nArmy = 0;
	Map *map = Map::getMapInstance();
	std::vector<Territory*> allTerritories = map->getTerritories();
	std::vector<Territory*>::iterator it;

	// Looking for all the territories that the player owns 
	for (it = allTerritories.begin(); it != allTerritories.end(); it++)
	{
		if ((*it)->getPlayerOwner()->getName() == name)
		{
			// Count the number of armies in this territory
			nArmy += (*it)->getAmountOfArmies();
		}
	}

	// Delete pointers
	delete map;
	allTerritories.clear();
	
	// Return number of armies
	return nArmy; 
}

/*
void Player::incArmy()
{
	nArmy++;

	notify();
}

void Player::decArmyToPlace()
{
	nArmy--;

	notify();
}*/

void Player::winTerritory()
{
	nTerritory++;

	notify();
}
/*
void Player::loseTerritory()
{
	nTerritory--;

	notify();
}*/

int Player::getNTerritory()
{
	// Local variables
	Map *map = Map::getMapInstance();
	std::vector<Territory*> allTerritories = map->getTerritories();
	std::vector<Territory*> playerTerritories;
	int nTerritory = 0;
	std::vector<Territory*>::iterator it;

	// Looking for all the territories that the player owns
	for (it = allTerritories.begin(); it != allTerritories.end(); it++)
	{
		if ((*it)->getPlayerOwner()->getName() == name)
		{
			std::cout << (*it)->getName() << std::endl;
			nTerritory++;
			playerTerritories.push_back((*it));
		}
	}

	allTerritories.clear();
	playerTerritories.clear();

	return nTerritory;
}

int Player::getNCard()
{
	return pDeck->getNumOfCards();
}

void Player::setNCard(int i)
{
	nCard = i;

	notify();
}

void Player::setNReinforcement(int n)
{
	nReinforcement = n; // TO UPDATE WITH REAL FUNCTIONS

	notify();
}

bool Player::getHasNewTerritory()
{
	return hasNewTerritory;
}

void Player::setHasNewTerritory(bool b)
{
	hasNewTerritory = b;

	notify();
}

int Player::getNReinforcement()
{
	return nReinforcement;
}

PlayerDeck* Player::getPDeck()
{
	return pDeck;
}
