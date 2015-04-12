#include "PlayerDeck.h"

// Constructor
PlayerDeck::PlayerDeck()
{
	numOfCards = 0;
	cards = {};
}

// Destructor
PlayerDeck::~PlayerDeck()
{
	cards.clear();
}

// Getters
std::vector<Card*> PlayerDeck::getCards()
{
	return cards;
}

/*void Deck::setListCards(int i, int j, int k)
{
this->getCards().at(0) += i;
this->getCards().at(1) += j;
this->getCards().at(2) += k;
}*/

int PlayerDeck::getNumOfCards()
{
	return cards.size();
}

// Setter
/*void PlayerDeck::setNumOfCards(int num)
{
	numOfCards = num;
}*/

// Others
void PlayerDeck::addCard(Card* aCard)		// aCard should be define with GameDeck::drawCard() function
{
	this->cards.push_back(aCard);
}

void PlayerDeck::removeCard(Card* aCard)
{
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards.at(i)->getTerritoryName() == aCard->getTerritoryName())
		{
			cards.erase(cards.begin() + i);
			break;
		}
	}
}

void PlayerDeck::printCards()
{
	if (cards.size() <= 0)
		std::cout << "No card.\n";
	else
	{
		for (int i = 0; i < cards.size(); i++)
		{
			std::cout << cards.at(i)->getTerritoryName() << ", ";
			std::cout << cards.at(i)->getTypeOfArmyStr() << std::endl;
		}
	}
}