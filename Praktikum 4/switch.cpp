#include "switch.h"

Switch::Switch(const std::string& texture, int row, int column) : Tile(texture, row, column), Floor(texture, row, column), Active()
{}

std::pair<bool, Tile*> Switch::onEnter(Character* who)
{
    this->activate();
    return {true, nullptr};
}
