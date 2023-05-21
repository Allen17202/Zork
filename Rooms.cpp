#include "Rooms.h"

using namespace Zork;

Room::Room()
{
	setRoom();
}

Room::Room(string location, string name, string description)
{
	setRoom(location, name, description);
}

void Room::setNeighbors(string north, string south, string east, string west)
{
	neighbors[NORTH] = north;
	neighbors[SOUTH] = south;
	neighbors[EAST] = east;
	neighbors[WEST] = west;
}

void Room::setRoom(string l, string n, string d)
{
	this->location = l;
	this->name = n;
	this->description = d;

	for (int i = 0; i < 4; i++)
	{
		neighbors[i] = "NOGO";
	}
}

void Room::lookRoom()
{
	cout << description << endl;
}

bool Zork::Room::isDirection(Direction loc)
{
	int numDirections = 4;
	for (int i = 0; i < numDirections; i++)
		if (loc == Direction(i) && neighbors[i] != "NOGO")
			return true;

	return false;
}

string Zork::Room::getNeighbor(Direction loc)
{
	return neighbors[loc];
}

string Zork::Room::getLocation()
{
	return location;
}
