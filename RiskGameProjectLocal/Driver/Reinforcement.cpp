#include "Reinforcement.h"

Reinforcement::Reinforcement()
{
	std::cout << "Reinforcement Phase.\n";
	map = Map::getMapInstance();
/*	cInfantry = 0;
	cCavalry = 0;
	cArtillery = 0;	*/
	numOfR = 0;
}

Reinforcement::Reinforcement(Player *p, int *c)
{
	std::cout << "Reinforcement Phase.\n";
	map = Map::getMapInstance();
	mCurrent = p;
/*	cInfantry = 0;
	cCavalry = 0;
	cArtillery = 0;	*/
	cardBonusCt = c;
	useCard = false;
	numOfR = 0;
}

void Reinforcement::territoryBonus()
{
	std::cout << "Counting the number of territories.\n";
	double count = mCurrent->getNTerritory();
	if (count >= 3)
		numOfR += (int)floor(count / 3);
	else
		numOfR += 3;
}


void Reinforcement::continentBonus()
{
	std::cout << "Counting the number of continents.\n";
	int bonus = 0;

	/*  Search in Player's ListOfContinents  */
/*
	if (map->getContinentByName("arthedain")->getPlayerOwner() == mCurrent)
		bonus += 2;
	if (map->getContinentByName("cardolan")->getPlayerOwner() == mCurrent)
		bonus += 2;
	if (map->getContinentByName("forodwaith")->getPlayerOwner() == mCurrent)
		bonus += 2;
	if (map->getContinentByName("gondor")->getPlayerOwner() == mCurrent)
		bonus += 2;
	if (map->getContinentByName("greenwood")->getPlayerOwner() == mCurrent)
		bonus += 5;
	if (map->getContinentByName("haradwaith")->getPlayerOwner() == mCurrent)
		bonus += 2;
	if (map->getContinentByName("mordor")->getPlayerOwner() == mCurrent)
		bonus += 3;
	if (map->getContinentByName("palisor")->getPlayerOwner() == mCurrent)
		bonus += 2;
	if (map->getContinentByName("rhudaur")->getPlayerOwner() == mCurrent)
		bonus += 2;
	if (map->getContinentByName("rohan")->getPlayerOwner() == mCurrent)
		bonus += 5;
	if (map->getContinentByName("wastelands")->getPlayerOwner() == mCurrent)
		bonus += 2;

	if (bonus == 0)
		std::cout << "No continent bonus.\n\n";
	else
	{
		std::cout << "Continent bonus: " << bonus << std::endl;
		numOfR += bonus;
	}
	*/
}


void Reinforcement::checkCards()
{
	if (mCurrent->getNCard() == 5)
	{
		std::cout << "Player must exchange its cards.\n\n";
		exchangeSet();
	}
	/* HERE!!!!!!!!!!!! */
	//std::cout << "Test: " << mCurrent->getListCards(0) << " " << mCurrent->getListCards(1) << " " << mCurrent->getListCards(2) << std::endl;
	if ((
			mCurrent->getPDeck()->getCards().at(0)->getTypeOfArmy() > 0
		 && mCurrent->getPDeck()->getCards().at(1)->getTypeOfArmy() > 0
		 && mCurrent->getPDeck()->getCards().at(2)->getTypeOfArmy() > 0
		 )
		|| mCurrent->getPDeck()->getCards().at(0)->getTypeOfArmy() >= 3
		|| mCurrent->getPDeck()->getCards().at(1)->getTypeOfArmy() >= 3
		|| mCurrent->getPDeck()->getCards().at(2)->getTypeOfArmy() >= 3
		)
	{
		std::cout << "Player may exchange its cards.\n\n";
		std::string ans;
		std::cin.ignore();
		std::cout << "Do you want to exchange? true or false.\n\n";
		std::cin >> ans;
		if (ans == "true")
			exchangeSet();
	}
}

void Reinforcement::exchangeSet()
{
	int ans;
	std::cin.ignore();
	std::cout << "Exchanging cards for an army: \n1) Set of Infantry-Cavalry-Artillery\n2) Set of Infantries\n3) Set of Cavalries\n4) Set of Artillery\n\n";
	std::cin >> ans;
	if (ans == 1)
	{
		mCurrent->setNCard(mCurrent->getNCard() - 3);
		mCurrent->getPDeck()->setListCards(mCurrent->getNCard() - 1, mCurrent->getNCard() - 1, mCurrent->getNCard() - 1);
		mCurrent->setNCard(mCurrent->getNCard() -3);
	}
	if (ans == 2)
	{
		mCurrent->setNCard(mCurrent->getNCard() - 3);
		mCurrent->getPDeck()->setListCards(mCurrent->getNCard() - 1, 0, 0);
		mCurrent->setNCard(mCurrent->getNCard() - 3);
	}
	if (ans == 3)
	{
		mCurrent->setNCard(mCurrent->getNCard() - 3);
		mCurrent->getPDeck()->setListCards(0, mCurrent->getNCard() - 1, 0);
		mCurrent->setNCard(mCurrent->getNCard() - 3);
	}
	if (ans == 4)
	{
		mCurrent->setNCard(mCurrent->getNCard() - 3);
		mCurrent->getPDeck()->setListCards(0, 0, mCurrent->getNCard() - 1);
		mCurrent->setNCard(mCurrent->getNCard() - 3);
	}

	useCard = true;
}

void Reinforcement::reinforce()
{
	mCurrent->setNReinforcement(numOfR);
	/*while (numOfR > 0)
	{
		std::cout << "Number of reinforcement: " << numOfR << std::endl;
		std::cout << "Please select a Territory to reinforce.\n\n";
		std::string s;
		std::cin >> s;
		chooseTerritory(s);
		std::cout << s << " has now a another army!\n\n";
		numOfR--;
		mCurrent->setNReinforcement(numOfR);
	}*/
}

void Reinforcement::chooseTerritory(std::string s)
{
	Territory *temp = map->getTerritoryByName(s);
	temp->setAmountOfArmies(temp->getAmountOfArmies() + 1);
}

int* Reinforcement::updateCardBonus()
{
	if (useCard)
		cardBonusCt += 5;
	return cardBonusCt;
}
