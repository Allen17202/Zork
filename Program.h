#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include "Rooms.h"

using namespace Zork;
class Program
{
public:
	Program();
	~Program();
	void Run();

private:
	bool setZorkRooms();
	void createRooms(string location, string name, string description, string north, string south, string east, string west);
	string userInput();
	Room* curRoomptr;
	map<string, Room*> zorkMap;
	bool gameFinished;
	string lastRoom;

};
