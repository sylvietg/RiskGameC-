#ifndef PLAYERDECK_H_
#define PLAYERDECK_H_

#include "IDeck.h"

class PlayerDeck: public IDeck
{
public:
	// Constructor & Destructor
	PlayerDeck();
	~PlayerDeck();

	// Getters
	std::vector<Card*> getCards();
	int getNumOfCards();

	// Setters
	//void setListCards(int i, int j, int k);
	void setNumOfCards(int num);
	void setCards(std::vector<Card*> set);

	// Others
	void addCard(Card* aCard);
	void removeCard(Card* aCard);
	void printCards();

private:
	std::vector<Card*> cards;
	int numOfCards;
};

#endif /* PLAYERDECK_H_ */
