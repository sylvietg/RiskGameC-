#include "Player.h"

Player::Player()
{
	//order = 0;
	mNumber = 0;
	name = "";
	nCard = 0;
	nTerritory = 0;
	nContinent = 0;
	nArmy = 0;
	nReinforcement = 0;
	nWin = 0;
	listCards[0] = 0;
	listCards[1] = 0;
	listCards[2] = 0;
	this->color = "green"; // default
}

Player::Player(std::string color)
{
	this->color = color;
}
Player::Player(int n)

{
	mNumber = n;
	name = "";
  	nCard = 0;
  	nTerritory = 0;
  	nContinent = 0;
  	nArmy = 0;
  	nReinforcement = 0;
  	nWin = 0;
  	listCards[0] = 0;
  	listCards[1] = 0;
  	listCards[2] = 0;
	this->color = "green"; // default
}


std::string Player::getColor()
{
	return this->color;
}
void Player::setName(std::string n)
{
	name = n;
}


void Player::setColor(std::string color)
{
	this->color = color;
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

void Player::setNArmy(int a)
{
	nArmy = a;
}

int Player::getNArmy()
{
	return nArmy;
}

void Player::incArmy()
{
	nArmy++;
}

void Player::decArmyToPlace()
{
	nArmy--;
}

void Player::winTerritory()
{
	nTerritory++;
}

void Player::loseTerritory()
{
	nTerritory--;
}

int Player::getNTerritory()
{
	return nTerritory;
}

/*
void Player::addCard()
{
	if (hasNewTerritory)
	{
		std::cout << "Player receives new card\n\n";
		hasNewTerritory = false;
		if (nCard > 5)
			std::cout << "Player has 5 cards and must exchange them in the next round.\n\n";
	}
	else
		std::cout << "No risk card.\n\n";
}
*/

int Player::getNCard()
{
	return nCard;
}

void Player::setNCard(int i)
{
	nCard = i;
}

int Player::getListCards(int i)
{
	return listCards[i];
}

void Player::setNReinforcement(int n)
{
	nReinforcement = n;
}

void Player::setListCards(int i, int j, int k)
{
	listCards[0] += i;
	listCards[1] += i;
	listCards[2] += i;
}

bool Player::getHasNewTerritory()
{
	return hasNewTerritory;
}

void Player::setHasNewTerritory(bool b)
{
	hasNewTerritory = b;
}

int Player::getNReinforcement()
{
	return nReinforcement;
}
