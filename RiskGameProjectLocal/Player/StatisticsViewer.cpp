/*
 * StatistcsViewer.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: orpheus
 */

#include "StatisticsViewer.h"

StatisticsViewer::StatisticsViewer()
{}

StatisticsViewer::StatisticsViewer(Player* aPlayer, sf::RenderWindow& aWindow) : observedPlayer (aPlayer), window (&aWindow)
{
	(this->observedPlayer)->attach(this);
}

StatisticsViewer::~StatisticsViewer()
{
	(this->observedPlayer)->detach(this);
}

void StatisticsViewer::update()
{
//	drawPlayerStatistics();
//	window->display();

}

void StatisticsViewer::drawPlayerStatistics()
{

//	std::cout << "STQ 1 - This Player has " << this->observedPlayer->getNTerritory() << " territories" << std::endl;
//	std::cout << "STQ 2 - This Player has " << this->observedPlayer->getNArmy() << " armies" << std::endl;
//	std::cout << "STQ 3 - This Player has " << this->observedPlayer->getNCard() << " cards" << std::endl;

}


