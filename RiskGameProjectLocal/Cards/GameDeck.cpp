#include "GameDeck.h"

// Constructor
GameDeck::GameDeck()
{
	map = Map::getMapInstance();
}

// Destructor
GameDeck::~GameDeck()
{
	cards.clear();
}

// Getters
std::vector<Card*> GameDeck::getCards()
{
	return cards;
}

// Others
void GameDeck::createDeck()
{
	/* Deck: total numOfCard = numOfTerritories + 2 wild cards */

	// Define regular Risk Card
	std::vector<Territory*> tempList = map->getTerritories();
	for (int i = 0; i < tempList.size(); i++)
	{
		Card *aCard = new Card(tempList.at(i)->getName());	// Card takes the name of a territory
		aCard->generateTypeOfArmy();						
		cards.push_back(aCard);
	}

	// Define wild cards
	cards.push_back(new Card("Wild Card"));
	cards.push_back(new Card("Wild Card"));
}

Card* GameDeck::drawCard()
{
	int numOfCards = cards.size();
	if (numOfCards > 0)
	{
		int randomIndex = rand() % numOfCards;
		Card *drawnCard = new Card(cards.at(randomIndex));
		cards.erase(cards.begin() + randomIndex);
		return drawnCard;
	}
	else
		return NULL;
}