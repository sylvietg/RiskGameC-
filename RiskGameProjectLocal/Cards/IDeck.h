#ifndef IDECK_H_
#define IDECK_H_

#include "Card.h"
#include <vector>

class IDeck
{
public:
	// Destructor
	//virtual ~IDeck();

	// Getters
	virtual std::vector<Card*> getCards() = 0;

	// Others
	virtual void addCard(Card* aCard) = 0;
	virtual void removeCard(Card* aCard) = 0;
	virtual void printCards() = 0;
};

#endif /* IDECK_H_ */
