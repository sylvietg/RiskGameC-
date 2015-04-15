#ifndef GAME_H_
#define GAME_H_

#include "../Map/Map.h"
#include "../Map/MapViewer.h"
#include "../Map/PlayerViewer.h"
#include "../Player/Player.h"
#include "../Player/StatisticsViewer.h"
#include "../Player/AIPlayer.h"
#include "../Cards/GameDeck.h"
#include "Reinforcement.h"
#include <math.h>

#include <stdlib.h>
#include "../Battle/Battle.h"
#include "StatusNotifier.h"

#include <SFML/Graphics.hpp>
#include "Fortification.h"
#include "../Map/MapIO/GameIO.h"
#include "../Map/MapIO/GameToMapIO.h"
#include "../Map/MapCreator/MapCreator.h"

class Game
{
public:
	//Start-up
	Game();
	virtual ~Game();
	void menu();
	void createPlayer();
	void turnOrder();
	int getNPlayer();
	int assignArmy();
	void placeArmy();
	void pickRandom();
	void graphics(std::string mapFileName);
	void startUp();

	//Main-play
	void mainPlay();
	void reinforcement();
	void battle();
	void fortification();

	//Other
	int rollDice();
	inline void updateTurnStatus();
	void drawCard();
	bool monitorWins();

private:
	Map *map;
	int nPlayer;
	Player **players;
	int d1, d2, a1, a2, a3; // Dices
	bool endGame;
	int ct;		// Index of the Current Player
	int first;
	int totArmy;
	int cardReinforcement;

	sf::RenderWindow window;
	sf::RenderTexture* bottomBar;

	StatusNotifier* statusNotifier;
	MapCreator* mapCreator;

	MapViewer* MapObserver;
	PlayerViewer* PlayerObserver;
	StatisticsViewer** StatisticsObserver;

	GameDeck gDeck;
};

#endif /* GAME_H_ */
