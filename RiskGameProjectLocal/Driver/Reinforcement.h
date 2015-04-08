#include <math.h>
#include "../Cards/Card.h"
#include "../Player/Player.h"
#include "../Map/Map.h"


class Reinforcement
{
public:
	Reinforcement();
	Reinforcement(Player *p, int *cardBonusCt);
	void checkCards();
	void exchangeSet();
	void territoryBonus();
	void continentBonus();
	void reinforce();
	void chooseTerritory(std::string s);
	int* updateCardBonus();
	
private:
	Map *map;
	Player *mCurrent;
/*	int cArtillery;
	int cCavalry;
	int cInfantry;	*/
	int numOfR;
	int *cardBonusCt;
	bool useCard;
};


