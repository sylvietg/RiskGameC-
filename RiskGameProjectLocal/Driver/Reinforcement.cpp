#include "Reinforcement.h"

/*Reinforcement::Reinforcement()
{
	std::cout << "Reinforcement Phase.\n";
	map = Map::getMapInstance();
	numOfR = 0;
}*/

Reinforcement::Reinforcement(Player *p, int *c)
{
	std::cout << "Reinforcement Phase.\n";
	mCurrent = p;
	cardBonusCt = c;
	useCard = false;
	numOfR = 0;
}

void Reinforcement::countTerritories()
{
	std::cout << "Counting the number of territories.\n";
	int count = mCurrent->getNTerritory();
	std::cout << "Num = " << count << std::endl;
	if (count >= 3)
		numOfR += (int)floor(count / 3);
	else
		numOfR += 3;
	std::cout << "Reinforcement = " << numOfR << std::endl;
}


void Reinforcement::countContinents()
{
	std::cout << "Counting the number of continents.\n";

	// Entire territory info
	Map *map = Map::getMapInstance();
	std::vector<Continent*> continents = map->getContinents();
	std::vector<Territory*> territories;

	// Check if the current player owns the continent
	std::vector<Continent*>::iterator it;
	for (it = continents.begin(); it != continents.end(); it++)
	{
		// Set the value of continent bonus 
		int bonus = (*it)->getBonus();

		territories = (*it)->getTerritories();
		std::vector<Territory*>::iterator it2;
		for (it2 = territories.begin(); it2 != territories.end(); it2++)
		{
			if ((*it2)->getPlayerOwner()->getName() != mCurrent->getName())
			{
				// Player is not the owner of the continent: no bonus -> set to 0
				bonus = 0;
				break;
			}
		}

		// Assign appropriate bonus value according to ownership status
		numOfR = bonus;
	}

	std::cout << "Reinforcement = " << numOfR << std::endl;

	// Delete pointers
	delete map;
	continents.clear();
	territories.clear();
}


void Reinforcement::countCards()
{
	int numOfCard = mCurrent->getNCard();

	if (mCurrent->getNCard() <= 5)
	{
		std::cout << "Player must exchange its cards.\n\n";
		exchangeCards();
	}
	else if (checkMinCondition())
	{	
		std::cout << "Player may exchange its cards.\n\n";
		std::string ans;
		std::cin.ignore();
		std::cout << "Do you want to exchange? true or false.\n\n";
		std::cin >> ans;
		if (ans == "true")
			exchangeCards();
	}
}

bool Reinforcement::checkMinCondition()
{
	int type0 = 0;
	int type1 = 0;
	int type2 = 0;

	PlayerDeck *pdeck = mCurrent->getPDeck();

	// Counting card per type
	for (int i = 0; i < mCurrent->getNCard(); i++)
	{
		int type = pdeck->getCards().at(i)->getTypeOfArmy();
		if (type == 0)
			type0++;
		else if (type == 1)
			type1++;
		else
			type2++;
	}

	// Delete pointer
	delete pdeck;
	
	// Check condition
	if (type0 >= 3 || type1 >= 3 || type2 >= 3 || (type0 > 0 && type1 > 0 && type2 > 0))
		return true;
	else
		return false;
}

void Reinforcement::exchangeCards()
{
	std::vector<Card*> deck = mCurrent->getPDeck()->getCards();
	Card* exchangeSet[3];

	// Listing the cards
	std::cout << "List of Cards (Select a set of 3 unique types or a set of 3 cards of the same type)\n\n";
	mCurrent->getPDeck()->printCards();

	// Asking the player to pick 3 cards
	do {
		int choice;

		for (int i = 1; i <= 3; i++)
		{
			std::cout << "Select card #:" << i - 1 << std::endl;
			std::cin.ignore();
			std::cin >> choice;
			exchangeSet[i-1] = deck.at(choice);
		}

	} while (!(exchangeSet[1]->getTypeOfArmy() == exchangeSet[2]->getTypeOfArmy() && exchangeSet[2]->getTypeOfArmy() == exchangeSet[3]->getTypeOfArmy()) ||		// Case: same type
		(exchangeSet[1]->getTypeOfArmy() == exchangeSet[2]->getTypeOfArmy() || exchangeSet[2]->getTypeOfArmy() == exchangeSet[3]->getTypeOfArmy()));			// Case: unique type 

	// Look for card territory extra bonus
	checkCardName(exchangeSet);
	
	// Update the player's & the game's number of reinforcements
	numOfR += (*cardBonusCt);
	cardBonusCt += 5;

	std::cout << "Reinforcement = " << numOfR << std::endl;

//	useCard = true;

	// Delete pointers
	deck.clear();
	delete exchangeSet;
}


void Reinforcement::checkCardName(Card* exchangeSet[3])
{
	// Looking for all the territories that the player owns
	Map *map = Map::getMapInstance();
	std::vector<Territory*> allTerritories = map->getTerritories();
	std::vector<Territory*>::iterator it;

	for (it = allTerritories.begin(); it != allTerritories.end(); it++)
	{
		bool eligible = false; // To control outer loop

		if (((*it)->getPlayerOwner()->getName() == mCurrent->getName()) && !eligible)
		{
			// Looking for card with the player's territory
			for (int i = 0; i < 3; i++)
			{
				// Check if eligible for extra 2 armies territory name bonus per turn
				if (exchangeSet[i]->getTerritoryName() == (*it)->getName())
				{
					// Assign 2 extra armies for this territory
					(*it)->setAmountOfArmies((*it)->getAmountOfArmies() + 2);
					eligible = true;
					break; // Break innerloop
				}
			}
		}
		else
			break; // Break outerloop
	}

	// Deleting pointers
	delete map;
	allTerritories.clear();
}

void Reinforcement::reinforce()
{
	/* Execute the counts */
	countTerritories();
	countContinents();
	countCards();

	/* Assign the number of reinforcements to the current player */
	mCurrent->setNReinforcement(numOfR);
}

/*int* Reinforcement::updateCardBonus()
{
	if (useCard)
		cardBonusCt += 5;
	return cardBonusCt;
} */
