/*Represent normal and wild card.*/
/*#pragma once
#include <math.h>
#include <string>
#include <iostream>*/

/* nTotCard = nTotTerri */
/*
class Deck
{
public:
	Deck();
private:
	Card deck[67];
};

Deck::Deck()
{
	for (int i = 1; i < 67; i++)
	{
		deck[i] = Card();
	}
}

class Card
{
public:
	class Card();
	int genCard();
	string setType();
private:
	int num; //1: infantry 2: Cavalry 3: Artillery
	string type;
};

Card::Card()
{
	cout << "Country Name, Type of Army \n";
	num = genCard();
	type = setType();
}

int Card::genCard()
{
	cout << "Choose randomly a country and a type of army. \n";
	return (rand() * 2) + 1;
}

string Card::setType()
{
	if (num == 1)
		return "infantry";
	else if (num == 2)
		return "cavalry";
	else
		return "artillery";
}
*/