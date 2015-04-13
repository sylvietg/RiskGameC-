#include "Reinforcement.h"

/*Reinforcement::Reinforcement()
{
	std::cout << "Reinforcement Phase.\n";
	map = Map::getMapInstance();
	numOfR = 0;
}*/

Reinforcement::Reinforcement(Player* p, int c)
{
	std::cout << "Reinforcement Phase.\n";
	mCurrent = p;
	cardBonusCt = c;
	exchange = false;
	numOfR = 0;
	//deck = mCurrent->getCards();
}

void Reinforcement::countTerritories()
{
	std::cout << "Counting the number of territories.\n";
	int count = mCurrent->getNTerritory();
	std::cout << "Num = " << count << std::endl;
	count = (int)floor(count / 3);
	if (count >= 3)
		numOfR += count;
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
		numOfR += bonus;
		
	}

	std::cout << "Reinforcement = " << numOfR << std::endl;
	std::cout << "End of Continent Bonus\n";
}

bool Reinforcement::checkMinCondition()
{
	int type1 = 0;
	int type2 = 0;
	int type3 = 0;

//	std::vector<Card*> *deck = this->mCurrent->getCards();
//	pdeck->printCards();

	// Counting card per type
	for (int i = 0; i < mCurrent->getNCard(); i++)
	{
		int type = mCurrent->getCards().at(i)->getTypeOfArmy();
		if (type == 1)
			type1++;
		else if (type == 2)
			type2++;
		else
			type3++;
	}

	// Delete pointer
/*	delete pdeck;
	pdeck = NULL;*/

	// Check condition
	if (type1 >= 3 || type2 >= 3 || type3 >= 3 || (type1 > 0 && type2 > 0 && type3 > 0))
		return true;
	else
	{
		//std::cout << "Do not meet mininal condition." << std::endl;
		return false;
	}
}

void Reinforcement::countCards()
{
	
	//std::cout << "Inside count card." << std::endl;
	//mCurrent->printCards();
	//PlayerDeck *deck = mCurrent->getPDeck();
	std::vector<Card*> cards = mCurrent->getCards();
	int numOfCard = mCurrent->getNCard();
	std::cout << "NumOfCards = " << numOfCard << std::endl;
	std::cout << "WTF" << std::endl;
	bool meetConditions = checkMinCondition();
	
	if (numOfCard >= 5)
	{
		std::cout << "Player must exchange its cards.\n\n";
		exchangeCards(cards);
		
	}
	else if (meetConditions)
	{	
		std::cout << "Player may exchange its cards.\n\n";
		std::string ans;
		std::cin.ignore();
		std::cout << "Do you want to exchange? true or false.\n\n";
		std::cin >> ans;
		if(ans == "true")
			exchangeCards(cards);

	}
	else
	{
		std::cout << "Cannot exchange." << std::endl;
	}
}



void Reinforcement::exchangeCards(std::vector<Card*> cards)
{
	//std::vector<Card*> pDeck = mCurrent->getCards();
	exchange = true;
	//this->mCurrent->getPDeck()->printCards();
	//std::vector<Card*> *cards = &(mCurrent->getPDeck()->getCards());
	Card* exchangeSet[3];

	// Listing the cards
	std::cout << "List of Cards (Select a set of 3 unique types or a set of 3 cards of the same type)\n\n";
//	deck->printCards();
	//std::vector<Card*> *set = &(deck->getCards());
	std::cout << "WTF" << std::endl;
	
	for (int i = 0; i < cards.size(); i++)
		{
			std::cout << i << ") " << cards.at(i)->getTerritoryName() << ", ";
			std::cout << cards.at(i)->getTypeOfArmyStr() << std::endl;
		}
	

	//mCurrent->notify();
	/*PlayerDeck *pDeck = mCurrent->getPDeck();
	std::vector<Card*> cards = pDeck->getCards();*/
	//std::cout << "SUCEED" << std::endl;
	// Asking the player to pick 3 cards
	do {
		int choice;

		for (int i = 0; i < 3; i++)
		{
			std::cout << "Select card #:" << (i + 1) << std::endl;
			std::cin.ignore();
			std::cin >> choice;
			exchangeSet[i] = cards.at(choice);
			//std::cout << exchangeSet[i]->getTypeOfArmy() << std::endl;
		}
		
	} while (!sameType(exchangeSet) && !uniqueType(exchangeSet));
	
	// Look for card territory extra bonus
	checkCardName(exchangeSet);

	std::cout << "Out!" << std::endl;
	/*c1 = exchangeSet[0];
	c2 = exchangeSet[1];
	c3 = exchangeSet[2];*/
	// Update PlayerDeck
	updatePDeck(exchangeSet/*c1, c2, c3*/, cards);
	
	
	//std::cout << "No error" << std::endl;

	// Assign appropriate bonus value
	//std::cout << "carBonus = " << cardBonusCt << std::endl;
	numOfR += cardBonusCt;


	std::cout << "Reinforcement = " << numOfR << std::endl;

}

void Reinforcement::updatePDeck(Card* exchangeSet[3]/*Card* c1, Card* c2, Card* c3*/, std::vector<Card*> cards)
{
	/*std::cout << "Before: " << std::endl;
	for (int i = 0; i < cards.size(); i++)
	{
		std::cout << i << ") " << cards.at(i)->getTerritoryName() << ", ";
		std::cout << cards.at(i)->getTypeOfArmyStr() << std::endl;
	}*/
	std::cout << "MID: " << std::endl;
	/*mCurrent->getPDeck()->removeCard(c1);
	mCurrent->getPDeck()->removeCard(c2);
	mCurrent->getPDeck()->removeCard(c3);*/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < cards.size(); j++)
		{
			if (cards.at(j)->getTerritoryName() == exchangeSet[i]->getTerritoryName())
			{
				cards.erase(cards.begin() + j);
				break;
			}
		}
	}

	/*	mCurrent->getPDeck()->removeCard(exchangeSet[0]);
	mCurrent->getPDeck()->removeCard(exchangeSet[1]);
	mCurrent->getPDeck()->removeCard(exchangeSet[2]);*/
	std::cout << "After: " << std::endl;
	for (int i = 0; i < cards.size(); i++)
	{
		std::cout << i << ") " << cards.at(i)->getTerritoryName() << ", ";
		std::cout << cards.at(i)->getTypeOfArmyStr() << std::endl;
}
	//updatedDeck = cards;
	mCurrent->setNCard(cards.size());
	mCurrent->setCards(cards);
	mCurrent->notify();
	//mCurrent->getPDeck()->setCards(updatedDeck);
}

/*std::vector<Card*> Reinforcement::getUpdatedDeck()
{
	return updatedDeck;
}*/

bool Reinforcement::sameType(Card* exchangeSet[3])
{
	return ((exchangeSet[0]->getTypeOfArmy() == exchangeSet[1]->getTypeOfArmy()) && (exchangeSet[1]->getTypeOfArmy() == exchangeSet[2]->getTypeOfArmy()));
}

bool Reinforcement::uniqueType(Card* exchangeSet[3])
{
	return ((exchangeSet[0]->getTypeOfArmy() != exchangeSet[1]->getTypeOfArmy()) && (exchangeSet[1]->getTypeOfArmy() != exchangeSet[2]->getTypeOfArmy())		// Case: unique type 
		&& (exchangeSet[0]->getTypeOfArmy() != exchangeSet[2]->getTypeOfArmy()));

}

void Reinforcement::checkCardName(Card* exchangeSet[3])
{
	std::cout << "Inside CHECK " << std::endl;
	// Looking for all the territories that the player owns
	Map *map = Map::getMapInstance();
	std::vector<Territory*> allTerritories = map->getTerritories();
	std::vector<Territory*>::iterator it;
	bool eligible = false; // To control outer loop
	std::cout << "INSIDE FIRST LOOP " << std::endl;
	for (it = allTerritories.begin(); it != allTerritories.end(); it++)
	{
		if (!eligible)
		{
			std::cout << "INSIDE FIRST LOOP " << std::endl;
			std::cout << (*it)->getName() << "," << (*it)->getPlayerOwner()->getName() << std::endl;


			if (((*it)->getPlayerOwner() == mCurrent) && !eligible)
			{
				std::cout << "INSIDE FIRST IF : PLAYERS'" << std::endl;
				std::cout << (*it)->getName() << std::endl;
				//break;
				// Looking for card with the player's territory
				for (int i = 0; i < 3; i++)
				{
					std::cout << "INSIDE SEC LOOP " << std::endl;
					// Check if eligible for extra 2 armies territory name bonus per turn
					if (exchangeSet[i]->getTerritoryName() == (*it)->getName())
					{
						std::cout << "INSIDE SEC IF " << std::endl;
						std::cout << exchangeSet[i]->getTerritoryName() << std::endl;
						// Assign 2 extra armies for this territory
						(*it)->setAmountOfArmies((*it)->getAmountOfArmies() + 2);
						eligible = true;
						break; // Break innerloop
					}
				}
			}
		}
		else
			break;// Break outerloop
	}
	std::cout << "Break! " << std::endl;
	// Deleting pointers
/*	delete map;
	allTerritories.clear();*/
}

void Reinforcement::reinforce()
{
	/* Execute the counts */
	countTerritories();
	countContinents();
	countCards();

	/* Assign the number of reinforcements to the current player */
	mCurrent->setNReinforcement(numOfR);
	
	mCurrent->notify();
	std::cout << "End REiNFORCEMENT\n";
}

int Reinforcement::updateCardBonus()
{
	//std::cout << "Bool: " << exchange << std::endl;
	if (exchange)
		cardBonusCt += 5;
	return cardBonusCt;
}

/*bool Reinforcement::getExchange()
{
	return exchange;
}

Card* Reinforcement::getC1()
{
	return c1;
}

Card* Reinforcement::getC2()
{
	return c2;
}

Card* Reinforcement::getC3()
{
	return c3;
}*/