/*
 * MapCreator.h
 *
 *  Created on: Apr 13, 2015
 *      Author: orpheus
 */

#ifndef MAP_MAPCREATOR_MAPCREATOR_H_
#define MAP_MAPCREATOR_MAPCREATOR_H_

#include "../Map.h"
#include <string>

class MapCreator
{
public:
	MapCreator();
	virtual ~MapCreator();

	std::string getFileName();
	void createAMap();

private:
	std::string fileName;
};

#endif /* MAP_MAPCREATOR_MAPCREATOR_H_ */
