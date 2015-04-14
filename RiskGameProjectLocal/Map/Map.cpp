/*
 * Map.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: mateus
 */

#include "Map.h"
#include <iostream>

Map *Map::mapInstance = NULL;

// SingleTone Instance
Map* Map::getMapInstance()
{
  if (!mapInstance)
    mapInstance = new Map();
  return mapInstance;
}

// constructors and destructor ---------------------------------
Map::Map()
{

}

Map::Map(std::vector<Continent*> continents)
{
  this->continents = continents;
}

Map::~Map()
{
  this->continents.clear();
}

// getter ---------------------------------------------------------
std::vector<Continent*> Map::getContinents()
{
  return this->continents;
}

std::vector<Territory*> Map::getTerritories()
{
  std::vector<Territory*> vt;
  int nContinents = this->continents.size();
  int nTerritories = 0;

  if (nContinents == 0)
	  std::cout << "No continents here." << std::endl; 
  // To remove in the final version ?
  // Replace by if (nContinent > 0) ??

  for (int i = 0; i < nContinents; i++)
    {
      nTerritories = this->continents.at(i)->getTerritories().size();

      for (int j = 0; j < nTerritories; j++)
	vt.push_back(this->continents.at(i)->getTerritories().at(j));
    }

  return vt;
}

std::string Map::getFileName()
{
	return this->fileName;
}

// setter ---------------------------------------------------------
void Map::setContinents(std::vector<Continent*> continents)
{
	this->continents = continents;

	notify();
}

void Map::setFileName(std::string fileName)
{
	this->fileName = fileName;

	notify();
}

void Map::printMyContinentsAndTerritory()
{
  int nContinents = this->continents.size();
  int nTerritories = 0;

  if (nContinents == 0)
    std::cout << "No continents here." << std::endl;

  for (int i = 0; i < nContinents; i++)
    {
      std::cout << this->continents.at(i)->getName() << std::endl;

      nTerritories = this->continents.at(i)->getTerritories().size();

      for (int j = 0; j < nTerritories; j++)
	std::cout << "  " << this->continents.at(i)->getTerritories().at(j)->getName() << std::endl;

    }

}

// other functions ----------------------------------------------
// - find and return a continent object in the list by the given name
Continent* Map::getContinentByName(std::string continent)
{
  int nContinents = this->continents.size();
  int index = nContinents;

  for (int i = 0; i < nContinents; i++)
    {
      if (continent == this->getContinents().at(i)->getName())
	{
	  index = i;
	  break;
	}
    }

  if (index == nContinents)
    {
      std::cout << "No Continent found with this name!" << std::endl;
      return NULL;
    }
  else
    return this->getContinents().at(index);

}

// - find and return a continent object in the list of continents by the given name
Territory* Map::getTerritoryByName(std::string territory)
{
  int nContinents = this->continents.size();
  int index = nContinents;

  if (nContinents == 0)
    std::cout << "No continents here, no territories to look for." << std::endl;

  for (int i = 0; i < nContinents; i++)
    {
      if (this->continents.at(i)->getTerritoryByName(territory)->getName() == territory)
	index = i;

    }

  if (index != nContinents)
    return this->continents.at(index)->getTerritoryByName(territory);
  else
    {
      Territory* limbo = new Territory();
      limbo->setName("Limbo");
      std::cout << "There is no Territory with that name in any Continent of this Map!" << std::endl;

      return limbo;
    }
}

// - Add a continent to the list of continents
void Map::addNewContinent(Continent* continent)
{
  int nContinents = this->continents.size();
  bool newContinent = true;

  for (int i = 0; i < nContinents; i++)
    {
      if (continent->getName() == this->continents.at(i)->getName())
	{
	  std::cout << "This Continent is already part of this map" << std::endl;
	  newContinent = false;
	}
    }

  if (newContinent)
    this->continents.push_back(continent);

}

// - Look for and remove a continent from the list of continents
void Map::removeContinent(Continent* continent)
{
  int nContinents = this->continents.size();
  bool continentExists = false;

  for (int i = 0; i < nContinents; i++)
    {
      if (continent->getName() == this->continents.at(i)->getName())
	{
	  this->continents.erase(this->continents.begin() + i);
	  continentExists = true;
	  break;
	}
    }

	if (!continentExists)
		std::cerr << "This continent isn't in this map!" << std::endl;

	notify();

}

// - Instantiate the continents


void
Map::loadMap (char* filename)
{

  MapIO mio;
  mio.loadMapInfo(filename);

/*

  // Reading lines
  char lineBuffer[302];
  char lineStream[302];
  std::string lineString;

  // Auxiliary for finding character position
  size_t posC;

  // Info for the viewMap
  std::string imageFileName;

  // Vector for the name of the continents
  std::vector<std::string> continents;

  // Vector for the info of the territories
  std::vector<std::string> continentsNames;

  // Flags for switching between the modes of parsing
  bool map = false;
  bool continent = false;
  bool territory = false;

  // File to be read
  FILE *fptr;

  if ((fptr = fopen(filename,"r")) == NULL)
    printf("Error! opening file");
  else
    {
      while (!feof(fptr))
	{
	  // Processing the line
	  fgets(lineBuffer, 300, fptr);
	  sscanf(lineBuffer, "%[^\n]s", lineStream);
	  lineString = std::string(lineStream);

	  // Looks for the map tag:
	  if(lineString.find("[Map]") == 0)
	    {
	      map = true;
	      continent = false;
	      territory = false;
	    }
	  // Looks for the continents tag:
	  else if(lineString.find("[Continents]") == 0)
	    {
	      map = false;
	      continent = true;
	      territory = false;
	    }
	  // Looks for the territories tag:
	  else if(lineString.find("[Territories]") == 0)
	    {
	      map = false;
	      continent = false;
	      territory = true;
	    }


	  if (map)
	    {
	      // Looks for the Image File name (image.bmp, image.png, etc)
	      if(lineString.find("image") == 0)
		{
			imageFileName = lineString.substr(6);
			//imageFileName = imageFileName.substr(0, imageFileName.size() - 1); // removes the break line character
			this->setFileName(imageFileName);
		}
	    }
	  else if (continent)
	    {
	      if (lineString.find("=") != -1)
		{
		  posC = lineString.find("=");

		  // Takes the continent name
		  std::string aContinent = lineString.substr(0, posC);
		  continentsNames.push_back(aContinent);

		  // Takes the continent reinforcement bonus
		  std::string aContinentBonusStr = lineString.substr(posC + 1);
		  std::stringstream convert(aContinentBonusStr);
		  int aContinentBonusInt;
		  if (!(convert >> aContinentBonusInt))
			  aContinentBonusInt = 0;

		  Continent* continentObject = new Continent();
		  continentObject->setName(aContinent);
		  continentObject->setBonus(aContinentBonusInt); // Define the continent bonus value for reinforcement
		  this->addNewContinent(continentObject);
		}

	    }
	  else if (territory)
	    {
	      if (lineString.find(",") != -1)
		{
		  Territory* territoryObject = new Territory();

		  // Takes the territory name
		  posC = lineString.find(","); // first comma
		  std::string aTerritoryName = lineString.substr(0, posC);

		  // Takes the xPosition
		  size_t posC1 = lineString.find(",", posC + 1); // second comma
		  std::string aTerritoryPosX = lineString.substr(posC+1, posC1 - posC - 1);

		  // Takes the yPosition
		  size_t posC2 = lineString.find(",", posC1 + 1); // third comma
		  std::string aTerritoryPosY = lineString.substr(posC1+1, posC2 - posC1 - posC - 1);

		  // Takes the Continent that the territory belong to
		  size_t posC3 = lineString.find(",", posC2 + 1); // fourth comma
		  std::string aTerritoryContinent = lineString.substr(posC2+1, posC3 - posC2 - 1);

		  // Takes the vector of Neighbors
		  size_t posC4 = lineString.find(",", posC3 ); // fifth comma
		  std::string aTerritoryListNeighbors = lineString.substr(posC4 + 1);

		  // Passes the whole info string to the vector of territories
		  std::stringstream territoryInfo;
		  territoryInfo << aTerritoryListNeighbors;

		  std::vector<std::string> aTerritoryNeighbors;
		  std::string aTerritoryNeighbor;

		  while (getline(territoryInfo, aTerritoryNeighbor, ','))
		    aTerritoryNeighbors.push_back(aTerritoryNeighbor);


		  for (int i = 0; i < aTerritoryNeighbors.size(); i++)
		    {

		      if (this->getTerritoryByName(aTerritoryNeighbors.at(i))->getName() == "Limbo" )
			{
			  Territory* territoryNeighborObject = new Territory();
			  territoryNeighborObject->setName(aTerritoryNeighbors.at(i));

			  territoryObject->addNewNeighbor(territoryNeighborObject);
			}
		      else
			{
			  territoryObject->addNewNeighbor(this->getTerritoryByName(aTerritoryNeighbors.at(i)));
			}
		    }

		  territoryObject->setName(aTerritoryName);
		  territoryObject->setPosX(atoi(aTerritoryPosX.c_str()));
		  territoryObject->setPosY(atoi(aTerritoryPosY.c_str()));

		  Continent* c;
		  c = this->getContinentByName(aTerritoryContinent);

		  (c->addNewTerritory(territoryObject));

		  std::cout << territoryObject->getName()
						     << ", posX = " << territoryObject->getPosX()
						     << ", posY = " << territoryObject->getPosY()
						     << ", continent = " << aTerritoryContinent
						     << ", neighbors: ";



		  for (int i = 0; i < territoryObject->getNeighbors().size(); i++)
		    {
		      std::cout << (territoryObject->getNeighbors().at(i))->getName() << ", ";
		    }
		  std::cout<<std::endl;
		  //std::cout<<this->getTerritoryByName(territoryObject->getName())->getName()<<std::endl;

		}

	    }

	}

      fclose(fptr);

      this->printMyContinentsAndTerritory();


      //cout << imageFileName;
    }
notify();
*/

}

std::vector<Territory*>
Map::getTerritoriesByPlayer (std::string player)
{
  std::vector<Territory*> vt;
    int nContinents = this->continents.size();
    int nTerritories = 0;

    if (nContinents == 0)
      std::cout << "No continents here." << std::endl;

    for (int i = 0; i < nContinents; i++)
    {
      nTerritories = this->continents.at(i)->getTerritories().size();

      for (int j = 0; j < nTerritories; j++)
      {
	  if(this->continents.at(i)->getTerritories().at(j)->getPlayerOwner()->getName() == player)
	    vt.push_back(this->continents.at(i)->getTerritories().at(j));
      }
    }
    return vt;
}
