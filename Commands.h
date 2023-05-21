#pragma once

#include <string>
#include <cstdlib>

namespace Zork
{
    enum class Commands
    {
        QUIT, Q = QUIT, EXIT = QUIT, BYE = QUIT,
        LOOK, L = LOOK,
        NORTH, N = NORTH,
        SOUTH, S = SOUTH,
        EAST, E = EAST,
        WEST, W = WEST,
        REWARD, R = REWARD,
        SCORE,
        INVENTORY, I = INVENTORY,
        TAKE,
        DROP,
        UNKNOWN
    };

    Commands ToCommand(const std::string& commandString);

    inline char toupper(char c)
    {
        return static_cast<char>(::toupper(c));
    }
}
