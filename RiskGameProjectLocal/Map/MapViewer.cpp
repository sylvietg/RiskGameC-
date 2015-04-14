/*
 * MapViewer.cpp
 *
 *  Created on: Mar 2, 2015
 *      Author: mateus
 */

#include "MapViewer.h"

MapViewer::MapViewer(Map* aMap, sf::RenderWindow &aWindow) : observedMap (aMap), window (&aWindow)
{
	observedMap->attach(this);

	for(int i = 0; i < this->observedMap->getContinents().size();i++)
	{
	    this->observedMap->getContinents()[i]->attach(this);
	}

	for(int i = 0; i < this->observedMap->getTerritories().size();i++)
	{
	    this->observedMap->getTerritories()[i]->attach(this);
	}

	loaded = false;

}

MapViewer::~MapViewer()
{
	(this->observedMap)->detach(this);
}

void MapViewer::update()
{


	loadMapImage(this->observedMap->getFileName());
	drawAllNeighborsLines();
	drawAllContinentOwners();
	//window->display();

	//

}

void MapViewer::drawNeighborLine(int x1, int y1, int x2, int y2, sf::Color color)
{
	 sf::VertexArray lines(sf::Lines, 2);

	 lines[0].position = sf::Vector2f(x1, y1);
	 lines[0].color = color;
	 lines[1].position = sf::Vector2f(x2, y2);
	 lines[1].color = color;

	 window->draw(lines);
}

void MapViewer::drawAllNeighborsLines()
{
	int nTerritories = observedMap->getTerritories().size();

	for (int i = 0; i < nTerritories; i++)
	{
		observedMap->getTerritories().at(i);

		int nNeighbors = observedMap->getTerritories().at(i)->getNeighbors().size();
		int tx = observedMap->getTerritories().at(i)->getPosX();
		int ty = observedMap->getTerritories().at(i)->getPosY();

		for(int j = 0; j < nNeighbors; j++)
		{
			int nx = observedMap->getTerritories().at(i)->getNeighbors().at(j)->getPosX();
			int ny = observedMap->getTerritories().at(i)->getNeighbors().at(j)->getPosY();

			if (tx != 0 && ty != 0 && nx != 0 && ny != 0)
				this->drawNeighborLine(tx, ty, nx, ny, sf::Color(255, 0, 0));
		}
	}
}

void MapViewer::drawContinentOwner(int xPos, int yPos, std::string continentColor)
{
	int circleSize = 21;
	xPos -= circleSize/2 + 5; // Adjusting the reference
	yPos -= circleSize;		// Adjusting the reference

	sf::CircleShape continentOwnerInTerritory(circleSize, 6);

	// Color of the Continent
	sf::Color color;

	if (continentColor == "blue")
		color = sf::Color(0, 0, 150);
	else if (continentColor == "red")
		color = sf::Color(150, 0, 0);
	else if (continentColor == "green")
		color = sf::Color(0, 150, 0);
	else if (continentColor == "black")
		color = sf::Color(0, 0, 0);
	else if (continentColor == "cyan")
		color = sf::Color(0, 150, 150);
	else if (continentColor == "magenta")
		color = sf::Color(150, 0, 150);
	else if (continentColor == "yellow")
		color = sf::Color(150, 150, 0);
	else if (continentColor == "gray")
			color = sf::Color(60, 60, 60);

	continentOwnerInTerritory.setFillColor(color);
	continentOwnerInTerritory.setPosition(xPos, yPos);

	// Draw the Player circle
	window->draw(continentOwnerInTerritory);

}

void MapViewer::drawAllContinentOwners()
{
	int nContinents = this->observedMap->getContinents().size();

	for(int i = 0; i < nContinents; i++)
	{
		int nTerritories = this->observedMap->getContinents().at(i)->getTerritories().size();

		for (int j = 0; j < nTerritories; j++)
			drawContinentOwner( this->observedMap->getContinents().at(i)->getTerritories().at(j)->getPosX(),
								this->observedMap->getContinents().at(i)->getTerritories().at(j)->getPosY(),
								this->observedMap->getContinents().at(i)->getColor()
							  );
	}
}

bool MapViewer::loadMapImage(std::string nameOfImage)
{

  if(!loaded){
	if (!mapBackground.loadFromFile(nameOfImage))
	{
		std::cerr << "Error trying to load the " << nameOfImage << " picture!" << std::endl;
		return false;
	}
	else
	{
		//std::cout << "Background map picture loaded successfully!" << std::endl;

		sf::Vector2u dimensions = mapBackground.getSize();

	  	if (dimensions.x >= 900)
	  		this->window->setSize(sf::Vector2u(dimensions.x, dimensions.y + 100));
	  	else
	  		this->window->setSize(sf::Vector2u(dimensions.x + (900 - dimensions.x), dimensions.y + 100));

		mapTexture.loadFromImage(mapBackground);
		spriteBackground.setTexture(mapTexture);

		this->window->draw(spriteBackground);

		loaded = true;

		return true;
	}
  }
  else
  {

      this->window->draw(spriteBackground);
      return true;
  }

}


