#include "input.h"

Input::Input(const int& horizontal, const int& vertical, bool exit) : horizontal(horizontal),
    vertical(vertical),
    exit(exit)
{}

int Input::getHorizontal() const
{
    return horizontal;
}

int Input::getVertical() const
{
    return vertical;
}

bool Input::getExit() const
{
    return exit;
}
