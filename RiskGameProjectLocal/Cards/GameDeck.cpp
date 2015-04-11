#include "GameDeck.h"

// Singletone Instance
GameDeck *GameDeck::gameDeckInstance = NULL;

GameDeck* GameDeck::getGameDeckInstance()
{
	if (!gameDeckInstance)
		gameDeckInstance = new GameDeck;
	return gameDeckInstance;
}

// Constructor
GameDeck::GameDeck() {}

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
	/* Deck: total numOfCard = numOfTerritories */

	Map* map = Map::getMapInstance();
	Card *aCard = NULL;
	// Define regular Risk Card
	std::vector<Territory*> tempList = map->getTerritories();
	for (int i = 0; i < tempList.size(); i++)
	{
		aCard = new Card(tempList.at(i)->getName());	// Card takes the name of a territory
		aCard->generateTypeOfArmy();						
		cards.push_back(aCard);
	}

	// Delete pointer
	delete map;
	delete aCard;
	tempList.clear();
}

void GameDeck::addCard(Card* aCard)
{
	this->cards.push_back(aCard);
}

void GameDeck::removeCard(Card* aCard)
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

void GameDeck::printCards()
{
	std::cout << "FIRST\n";
	//std::vector<Card*>::iterator it;
	if (cards.size() <= 0)
		std::cout << "No card.\n";
	else
	{
		std::cout << "HERE\n";
		for (int i = 0; i < cards.size(); i++)
		{
			std::cout << cards.at(i)->getTerritoryName() << ", ";
			std::cout << cards.at(i)->getTypeOfArmyStr() << std::endl;
		}

	}
		
}