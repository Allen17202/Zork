
#include "Program.h"

using namespace std;
using namespace Zork;

Program::Program()
{
	curRoomptr = nullptr;
	gameFinished = false;

	bool gamestate = setZorkRooms();
	if (!gamestate)
	{
		gameFinished = true;
	}
}

Program::~Program()
{
	for (auto& roomPtr : zorkMap)
	{
		if (roomPtr.second != nullptr)
		{
			delete roomPtr.second;
		}
	}
}

void Program::Run()
{
	cout << endl;
	string state = "";
	cout << "Welcome to Zork" << endl;
	curRoomptr->lookRoom();
	cout << endl;
	while (!gameFinished)
	{
		cout << curRoomptr->name << endl;
		if (curRoomptr->getLocation() == lastRoom)
		{
			gameFinished = true;
			continue;
		}
		cout << ">";
		state = userInput();
	}
	cout << endl << "Thank you for playing";
}

bool Program::setZorkRooms()
{
	string buf;
	string location, name, description, north, south, east, west;
	string fileName = "Content/Rooms.txt";
	ifstream input(fileName);

	if (!input.good())
	{
		cout << "Error with opening file" << endl;
		return false;
	}

	while (input >> buf)
	{
		if (buf == "StartRoom")
		{
			input >> buf;
			curRoomptr = zorkMap[buf];
		}
		else if (buf == "Start")
		{
			input >> location;
			input.ignore();
			getline(input, name);
			getline(input, description);
			input >> buf;
			input >> north;
			input >> buf;
			input >> south;
			input >> buf;
			input >> east;
			input >> buf;
			input >> west;
			createRooms(location, name, description, north, south, east, west);
		}
	}
	return true;
}

void Program::createRooms(string location, string name, string description, string north, string south, string east, string west)
{
	zorkMap[location] = new Room(location, name, description);
	zorkMap[location]->setNeighbors(north,south,east,west);
}

string Program::userInput()
{
	string state ="";
	string userInput = "";
	bool canMove = false;
	cin >> userInput;

	for (int i = 0; i < 4; i++)
	{
		Direction dir = Direction(i);
		string arrow = getStringFromDirection(dir);
		string letterArr = arrow.substr(0, 1);

		if (userInput == arrow || userInput == letterArr)
		{
			canMove = true;
			if (curRoomptr->isDirection(dir))
			{
				state = "You went " + getStringFromDirection(dir);
				string key = curRoomptr->getNeighbor(dir);
				curRoomptr = zorkMap[key];
			}
			else
			{
				state = "The way is shut!";
				break;
			}
		}
		else if (userInput == "quit" || userInput == "QUIT" || userInput == "Q" || userInput == "q")
		{
			gameFinished = true;
			return state;
		}
		else if (userInput == "LOOK" || userInput == "look" || userInput == "l" || userInput == "L")
		{
			cout << curRoomptr->description << endl;
			return state;
		}
		else
		{
			state = "Unknown Command";
		}

	
	}


	if (!canMove)
	{
		state = "Unknown Command";
	}

	return state;
}
