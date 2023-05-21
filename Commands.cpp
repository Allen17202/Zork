#include "Commands.h"
#include <algorithm>
#include <map>

using namespace std;
using namespace Zork;

namespace Zork
{
	Commands ToCommand(const string& commandString)
	{
		static std::map<string, Commands> commandMap =
		{
			{"QUIT", Commands::QUIT },
			{"Q", Commands::Q },
			{"EXIT", Commands::EXIT },
			{"BYE", Commands::BYE },
			{"NORTH", Commands::NORTH },
			{"SOUTH", Commands::SOUTH },
			{"EAST", Commands::EAST },
			{"WEST", Commands::WEST },
			{"REWARD", Commands::REWARD },
			{"R", Commands::R },
			{"SCORE", Commands::SCORE },
			{"INVENTORY", Commands::INVENTORY },
			{"I", Commands::I },
			{"TAKE", Commands::TAKE },
			{"DROP", Commands::DROP },
			{"UNKNOWN", Commands::UNKNOWN },
		};

		string uppercaseString;
		uppercaseString.resize(commandString.size());
		transform(commandString.begin(), commandString.end(), uppercaseString.begin(), Zork::toupper);
		map<string, Commands>::const_iterator found = commandMap.find(uppercaseString);
		return (found != commandMap.end() ? found->second : Commands::UNKNOWN);
    }
}