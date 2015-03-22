#ifndef GAME_H_
#define GAME_H_

#include "../Map/Map.h"
#include "../Map/MapViewer.h"
#include "../Map/PlayerViewer.h"
#include "../Player/Player.h"
#include "../Player/AIPlayer.h"
//#include "Dice.h"
#include "Reinforcement.h"
#include <math.h>

#include <stdlib.h>
#include "../Battle/Battle.h"

#include <SFML/Graphics.hpp>
//#include "Fortification.h"
//#include "Deck.h"

class Game
{
public:
	//Start-up
	Game();
	void createPlayer();
	void turnOrder();
	int getNPlayer();
	int assignArmy();
	void placeArmy();
	void pickRandom();
	void graphics();
	//void ownCountry(Country c, Player p);
	void startUp();

	//Main-play
	void mainPlay();

	//Reinforcement
	void reinforcement();

	void battle();


	//Other
	int rollDice();
	void drawCard();

private:
	Map *map;
	int nPlayer;
	Player **players;
	int d1, d2, a1, a2, a3; // Dices
	bool endGame;
	int ct;
	int first;
	int totArmy;
	//Deck deck;
	int cardReinforcement;
	sf::RenderWindow window;
	MapViewer* MapObserver;
	PlayerViewer* PlayerObserver;
};

#endif /* GAME_H_ */
