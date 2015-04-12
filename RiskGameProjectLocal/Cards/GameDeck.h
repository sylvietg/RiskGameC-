#ifndef GAMEDECK_H_
#define GAMEDECK_H_

#include "IDeck.h"
#include "../Map/Map.h"

class GameDeck: public IDeck
{
public:
	// Singleton Instance
	static GameDeck* getGameDeckInstance();
	// Constructor & Destructor
	GameDeck();
	~GameDeck();

	// Getters
	std::vector<Card*> getCards();
//	int getNumOfCards(); IN DECK: USED HERE?

	// Others
	void createDeck();
	void addCard(Card* aCard);
	void removeCard(Card* aCard);
	void printCards();
	Card* drawCard();

private:
	std::vector<Card*> cards;
	
	// Singleton Instance
	static GameDeck *gameDeckInstance;
};

#endif /* GAMEDECK_H_ */
