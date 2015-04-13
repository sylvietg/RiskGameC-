/*
 * MapCreator.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: orpheus
 */

#include "MapCreator.h"

MapCreator::MapCreator()
{
}

MapCreator::~MapCreator()
{
	// TODO Auto-generated destructor stub
}

std::string MapCreator::getFileName()
{
	return fileName;
}

void MapCreator::createAMap()
{
	Map* map = Map::getMapInstance();

	std::cout << ">>#>>#>>#>>#>-- RISK! - MAP CREATOR --<#<<#<<#<<#<<"	<< std::endl;
	std::cout << "--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--^--"	<< std::endl;
	std::cout << "                                   			    "	<< std::endl;
	std::cout << "Give a name for your .map file: " 					<< std::endl;

	std::cin.get();
	std::getline(std::cin, this->fileName);

	std::cout << "How many Continents there will be? " 					<< std::endl;
}
