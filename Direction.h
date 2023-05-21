#pragma once
#include <string>

using namespace std;

enum Direction {
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

string getStringFromDirection(Direction direction);
