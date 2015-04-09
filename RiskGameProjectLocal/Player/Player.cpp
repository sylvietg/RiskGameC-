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
	this->color = "gray"; // default
	pDeck = new Deck;
}

Player::Player(std::string color)
{
	this->color = color;
	pDeck = new Deck;
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
	this->color = "green"; // default
	pDeck = new Deck;
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

void Player::setNArmy(int a)
{
	nArmy = a;

	notify();
}

int Player::getNArmy()
{
	return nArmy;
}

void Player::incArmy()
{
	nArmy++;

	notify();
}

void Player::decArmyToPlace()
{
	nArmy--;

	notify();
}

void Player::winTerritory()
{
	nTerritory++;

	notify();
}

void Player::loseTerritory()
{
	nTerritory--;

	notify();
}

int Player::getNTerritory()
{
	return nTerritory;
}

int Player::getNCard()
{
	return nCard;
}

void Player::setNCard(int i)
{
	nCard = i;

	notify();
}

void Player::setNReinforcement(int n)
{
	nReinforcement = n;

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

Deck* Player::getPDeck()
{
	return pDeck;
}
