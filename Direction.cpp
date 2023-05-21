#include "Direction.h"

string getStringFromDirection(Direction loc)
{
    if (loc == NORTH)
    {
        return "NORTH";
    }
    else if (loc == SOUTH)
    {
        return "SOUTH";
    }
    else if (loc == EAST)
    {
        return "EAST";
    }
    else if (loc == WEST)
    {
        return "WEST";
    }
    else
    {
        return "UNKNOWN";
    }
}
