#ifndef DECK_H_
#define DECK_H_

#include "Card.h"
#include <vector>

class Deck
{
public:
	// Constructor & Destructor
	Deck();
	virtual ~Deck();

	// Getters
	virtual std::vector<Card*> getCards();
	int getNumOfCards();

	// Setters
	void setListCards(int i, int j, int k);
	void setNumOfCards(int num);

	// Others
	virtual void addCard(Card* aCard);
	virtual void removeCard(Card* aCard);
private:
	std::vector<Card*> cards;
	int numOfCards;
};

#endif /* DECK_H_ */
