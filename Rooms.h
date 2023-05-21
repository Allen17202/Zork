#pragma once
#include <string>
#include <iostream>
#include "Direction.h"

using namespace std;
namespace Zork
{
	struct Room
	{
		Room();
		Room(string location, string name, string description);
		void setNeighbors(string north, string south, string east, string west);
		void setRoom(string loc = "", string name = "", string description = "");

		void lookRoom();
		bool isDirection(Direction loc);
		string getNeighbor(Direction loc);
		string getLocation();

		string location;
		string name;
		string description;
		string neighbors[4];
	};
}


