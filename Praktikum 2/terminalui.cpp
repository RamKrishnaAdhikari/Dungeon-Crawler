#include "terminalui.h"
#include <iostream>


void TerminalUI::draw(Level* level)
{
    for (size_t i = 0; i < level->getHeight(); i++)
    {
        for (size_t j = 0; j < level->getWidth(); j++)
        {
            if (level->getMap().at(i).at(j)->hasCharacter())
            {
                std::cout << "X";
            }
            else
            {
                std::cout << level->getMap().at(i).at(j)->getTexture();
            }
        }
        std::cout << std::endl;
    }
}

Input TerminalUI::move()
{
    char userInput = ' ';

    std::cout << "Bitte geben Sie Richtung A⬅︎: D➡: W⬆︎: S⬇︎: X: Exit :";
    std::cin >> userInput;

    switch (userInput)
    {
    case 'A':
    case 'a':
        return Input(-1, 0, false);
    case 'D':
    case 'd':
        return Input(1, 0, false);
    case 'W':
    case 'w':
        return Input(0, -1, false);
    case 'S':
    case 's':
        return Input(0, 1, false);
    case 'X':
    case 'x':
        return Input(0, 0, true);
    default:
        std::cerr << "Invalid Input. Please enter A, D, W, S, X." << std::endl;
        return Input(0, 0, false);
    }
}
