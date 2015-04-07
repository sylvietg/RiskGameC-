#ifndef GAMEDECK_H_
#define GAMEDECK_H_

#include "Deck.h"
#include "../RiskGameProjectLocal/Map/Map.h"
#include <vector>

class GameDeck: public Deck
{
public:
	// Constructor & Destructor
	GameDeck();
	~GameDeck();

	// Getters
	std::vector<Card*> getCards();

	// Others
	void createDeck();
/*	void addCard(Card* aCard);
	void removeCard(Card* aCard);*/
	Card* drawCard();

private:
	std::vector<Card*> cards;
	Map *map;
};

#endif /* GAMEDECK_H_ */