#include "dungeoncrawler.h"
<<<<<<< HEAD
#include "graphicalui.h"
#include <fstream>
#include <iostream>
#include <istream>
#include"door.h"
#include "attackcontroller.h"
#include"abstractcontroller.h"
#include"stationarycontroller.h"
#include"guardiancontroller.h"
#include<sstream>
#include<stdexcept>
DungeonCrawler::DungeonCrawler() {}

DungeonCrawler::DungeonCrawler(Level* level):
    level(level),
    level_num(0)
{
    lootchest_found = false;
    human_alive = true;
    push_level_back(level);
}

DungeonCrawler::DungeonCrawler(int rows, int cols, std::string l):
 level(new Level(rows, cols, l)),
    level_num(0)
{
    lootchest_found = false;
    human_alive = true;
    push_level_back(level);
=======
#include "character.h"
#include "level.h"
//#include <iostream>

DungeonCrawler::DungeonCrawler(Level* currentLevel) :
    currentLevel(currentLevel)
{
    // Test copy constructor
    /*std::cout << "Testing copy constructor" << std::endl;
    auto* tmp = new Level(10, 10, "##########"
                                  "#O.....C.#"
                                  "#...<....#"
                                  "#..___...#"
                                  "#..___...#"
                                  "#........#"
                                  "#######X##"
                                  "#O.......#"
                                  "#...?....#"
                                  "##########");
    std::cout << "Created tmp : " << std::endl;
    terminalui->draw(tmp);

    currentLevel = new Level(*tmp);
    std::cout << "Copy constructor called created new level : " << std::endl;
    terminalui->draw(currentLevel);

    delete tmp;
    std::cout << "Tmp deleted" << std::endl;

    std::cout << std::endl;

    // Test assignment
    tmp = new Level(10, 10, "##########"
                            "#O.......#"
                            "#...<....#"
                            "#..___...#"
                            "#C.___...#"
                            "#........#"
                            "#######X##"
                            "#O.......#"
                            "#...?....#"
                            "##########");
    std::cout << "Created new tmp : " << std::endl;
    terminalui->draw(tmp);

    *currentLevel = *tmp;
    std::cout << "Called assignment operator : " << std::endl;
    terminalui->draw(currentLevel);

    delete tmp;
    std::cout << "Cleaned everything up" << std::endl;*/
>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
}

DungeonCrawler::~DungeonCrawler()
{
<<<<<<< HEAD
    saveGame();
    delete gr_ui;
    gr_ui = nullptr;
    //delete current_level;
  level = nullptr;
}

void DungeonCrawler::setGr_ui(GraphicalUI* newGr_ui)
{
    gr_ui = newGr_ui;
}

void DungeonCrawler::push_level_back(Level *level_n)
{
    level_list.push_back(level_n);
    if(level_list.second_to_last() == nullptr)
    {
        (level_list.begin().operator *())->getLevel_ch()->setDestination(level_n->getChar_set());
        (level_list.begin().operator *())->getLevel_ch()->setLevel_dest(level_n);

        if(!(level_n->getLevel_ch() == nullptr))
        {
            level_n->getLevel_ch()->setDestination((level_list.begin().operator *())->getChar_set());
            level_n->getLevel_ch()->setLevel_dest((level_list.begin().operator *()));
        }
    }
    else
    {
        level_list.second_to_last()->getLevel_ch()->setDestination(level_n->getChar_set());
        level_list.second_to_last()->getLevel_ch()->setLevel_dest(level_n);

        if(!(level_n->getLevel_ch() == nullptr))
        {
            level_n->getLevel_ch()->setDestination(level_list.begin().operator *()->getChar_set());
            level_n->getLevel_ch()->setLevel_dest(level_list.begin().operator *());
        }
    }

    if(level_list.begin().operator *() != level_n){
        for(auto chara:level_list.begin().operator *()->getCharacters()){
            if(chara->isHuman()){
                level_n->addCharacter(chara);
            }
        }
    }
}

void DungeonCrawler::check_alive()
{
    int ind = 0;
    for(auto charac : level->getCharacters())
    {
        if(!(charac->getAlive()))
        {
            if(charac->isHuman())
            {
                human_alive = false;
            }
            charac->getChar_tile()->setCharacter(nullptr);
            level->removeCharacter(ind);
        }
        ind++;
    }
}

bool DungeonCrawler::isHuman_alive() const
{
    return human_alive;
}

bool DungeonCrawler::getLootchest_found() const
{
    return lootchest_found;
}


/*
void DungeonCrawler::loadGame() {
    std::remove("/Users/vedantsorout/Desktop/DungeonCrawler_premium_graph/build/savegame.txt");
    std::ifstream file("/Users/vedantsorout/Desktop/DungeonCrawler_premium_graph/build/savegame1.txt");
    if (!file) {
        std::cerr << "Unable to open file for loading" << std::endl;
        return;
    }

    file >> level_num >> lootchest_found >> human_alive;

    // Clear existing levels
    for (auto it = level_list.begin(); it != level_list.end(); ++it) {
        delete *it;
    }


    std::string line;
    while (std::getline(file, line)) {
        if (line == "EndLevel") continue;

        std::istringstream iss(line);
        int rows, cols;
        iss >> rows >> cols;

        std::string lvl_string;
        std::getline(file, lvl_string);

        Level* newLevel = new Level(rows, cols, lvl_string);

        // Load door states
        while (std::getline(file, line) && line != "EndLevel") {
            std::istringstream iss(line);
            int row, col;
            bool isOpen;
            iss >> row >> col >> isOpen;
            if (Door* door = dynamic_cast<Door*>(newLevel->getTile(row, col))) {
                door->setOpen(isOpen);
            }
        }

        // Load characters
        while (std::getline(file, line) && line != "EndLevel") {
            std::istringstream iss(line);
            std::string texture;
            int row, col, strength, stamina;
            bool isHuman;
            iss >> texture >> row >> col >> strength >> stamina >> isHuman;

            Character* character = new Character(texture, strength, stamina, isHuman);
            newLevel->placeCharacter(character, row, col);
            newLevel->addCharacter(character);

            // If it's an NPC, load controller
            if (!isHuman) {
                std::getline(file, line);
                if (line.substr(0, 10) == "Controller") {
                    std::string controllerType = line.substr(11);
                    AbstractController* controller = nullptr;

                    if (controllerType == "Attack") {
                        controller = new AttackController(newLevel);
                        static_cast<AttackController*>(controller)->setAttacker(character);
                    } else if (controllerType == "Stationary") {
                        controller = new StationaryController();
                    } else if (controllerType.substr(0, 8) == "Guardian") {
                        controller = new GuardianController(controllerType.substr(9));
                    }

                    if (controller) {
                        character->setAbstrCon(controller);
                    }
                }
            }
        }

        level_list.push_back(newLevel);
    }

    // Set current level
    level = *level_list.begin();
    for (int i = 0; i < level_num; i++) {
        level = level->getLevel_ch()->getLevel_dest();
    }

    file.close();
}*/

void DungeonCrawler::saveGame() {
    std::ofstream file("/Users/vedantsorout/Desktop/Praktikum6/build/save1.txt");

    if (!file) {
        std::cerr << "Unable to open file" << std::endl;
        return;

    }

    if (file.is_open()) {
        file << level->getRows() << std::endl;
        file << level->getCols() << std::endl;
        file << lootchest_found << std::endl;
        file << human_alive << std::endl;

        for (auto it = level_list.begin(); it != level_list.end(); ++it) {
            Level* level = *it;
            file << level->getRows() << " " << level->getCols() << std::endl;
            file << level->getLvl_string() << std::endl;

            // Save door states
            for (int i = 0; i < level->getRows(); i++) {
                for (int j = 0; j < level->getCols(); j++) {
                    Tile* tile = level->getTile(i, j);
                    if (Door* door = dynamic_cast<Door*>(tile)) {
                        file << i << " " << j << " " << door->getOpen() << std::endl;
                    }
                }
            }

            file << "EndDoors" << std::endl;

            // Save characters
            for (auto character : level->getCharacters()) {
                file << character->getTexture() << " "
                     << character->getChar_tile()->getRow() << " "
                     << character->getChar_tile()->getCol() << " "
                     << character->getStrength() << " "
                     << character->getStamina() << " "
                     << character->isHuman() << std::endl;
                if (!character->isHuman() && character->getAbstrCon()) {
                    if (dynamic_cast<AttackController*>(character->getAbstrCon())) {
                        file << "Controller Attack" << std::endl;
                    } else if (dynamic_cast<StationaryController*>(character->getAbstrCon())) {
                        file << "Controller Stationary" << std::endl;
                    } else if (auto guardController = dynamic_cast<GuardianController*>(character->getAbstrCon())) {
                        file << "Controller Guardian " << guardController->getMove_str()<< std::endl;
                    }
                }
            }

            file << "EndCharacters" << std::endl;
        }

        file << "EndLevel" << std::endl;
    }
    file.close();
}
void DungeonCrawler::loadGame() {
    std::remove("/Users/vedantsorout/Desktop/Praktikum6/build/save.txt");
    std::ifstream file("/Users/vedantsorout/Desktop/Praktikum6/build/save1.txt");

    if (!file) {
        std::cerr << "Unable to open file for loading" << std::endl;
        return;

    }
    try {


    int rows, cols;
    bool lootchestFound, humanAlive;

    file >> rows >> cols >> lootchestFound >> humanAlive;
    lootchest_found = lootchestFound;
    human_alive = humanAlive;

    // Clear existing levels
    for (auto it = level_list.begin(); it != level_list.end(); ++it) {
        delete *it;
    }


    std::string line;
    while (std::getline(file, line)) {
        if (line == "EndLevel") break;

        std::istringstream iss(line);
        iss >> rows >> cols;

        std::string lvl_string;
        std::getline(file, lvl_string);

        Level* newLevel = new Level(rows, cols, lvl_string);

        // Load door states
        while (std::getline(file, line) && line != "EndDoors") {
            std::istringstream iss(line);
            int row, col;
            bool isOpen;
            iss >> row >> col >> isOpen;
            if (Door* door = dynamic_cast<Door*>(newLevel->getTile(row, col))) {
                door->setOpen(isOpen);
            }
        }

        // Load characters
        while (std::getline(file, line) && line != "EndCharacters") {
            std::istringstream iss(line);
            std::string texture;
            int row, col, strength, stamina;
            bool isHuman;
            iss >> texture >> row >> col >> strength >> stamina >> isHuman;

            Character* character = new Character(texture, strength, stamina, isHuman);
            newLevel->placeCharacter(character, row, col);
            newLevel->addCharacter(character);

            if (!isHuman) {
                std::getline(file, line);
                if (line.substr(0, 10) == "Controller") {
                    std::string controllerType = line.substr(11);
                    AbstractController* controller = nullptr;

                    if (controllerType == "Attack") {
                        controller = new AttackController(newLevel);
                        static_cast<AttackController*>(controller)->setAttacker(character);
                    } else if (controllerType == "Stationary") {
                        controller = new StationaryController();
                    } else if (controllerType.substr(0, 8) == "Guardian") {
                        std::string behavior = controllerType.substr(9);
                        controller = new GuardianController(behavior);
                    }

                    if (controller) {
                        character->setAbstrCon(controller);
                    }
                }
            }
        }

        level_list.push_back(newLevel);
    }

    // Set current level
    level = *level_list.begin();
    for (int i = 0; i < level_num; i++) {
        level = level->getLevel_ch()->getLevel_dest();
    }

    file.close();
}


catch (const std::exception &e)
{
std::cerr<<"error "<<e.what()<<std::endl;
}
}
/*
void DungeonCrawler::saveGame()
{

    std::ofstream file("/Users/vedantsorout/Desktop/DungeonCrawler_premium_graph/build/savegame1.txt");

    if(!file)
    {
        std::cerr << "Unable to open file" << std::endl;
        return;
    }
    if(file.is_open())
    {

            file << level->getRows() << std::endl;
            file << level->getCols() << std::endl;
            file << lootchest_found << std::endl;
            file << human_alive << std::endl;

            for (auto it = level_list.begin(); it != level_list.end(); ++it) {
                Level* level = *it;
                file << level->getRows() << " " << level->getCols() << std::endl;
                file << level->getLvl_string() << std::endl;

                // Save door states
                for (int i = 0; i < level->getRows(); i++) {
                    for (int j = 0; j < level->getCols(); j++) {
                        Tile* tile = level->getTile(i, j);
                        if (Door* door = dynamic_cast<Door*>(tile)) {
                            file << i << " " << j << " " << door->getOpen() << std::endl;
                        }
                    }
                }

                // Save characters
                for (auto character : level->getCharacters()) {
                    file << character->getTexture() << " "
                         << character->getChar_tile()->getRow() << " "
                         << character->getChar_tile()->getCol() << " "
                         << character->getStrength() << " "
                         << character->getStamina() << " "
                         << character->isHuman() << std::endl;
                    if (!character->isHuman() && character->getAbstrCon()) {
                        if (dynamic_cast<AttackController*>(character->getAbstrCon())) {
                            file << "Controller Attack" << std::endl;
                        } else if (dynamic_cast<StationaryController*>(character->getAbstrCon())) {
                            file << "Controller Stationary" << std::endl;
                        } else if (auto guardController = dynamic_cast<GuardianController*>(character->getAbstrCon())) {
                            file << "Controller Guardian ";
                            for (int move : guardController->getResults()) {
                                file << move;
                            }
                            file << std::endl;
                        }
                    };

                }
        file << -1;
            }
            file << "EndLevel" << std::endl;

    }
    file.close();
        }
*/
int DungeonCrawler::getLevel_num() const
{
    return level_num;
}

void DungeonCrawler::setLevel_num(int newLevel_num)
{
    level_num = newLevel_num;
}

bool DungeonCrawler::turn()
{
    bool stop = false;

    bool Moved = false;
    for(Character* character:level->getCharacters()){
        bool dooropended = false;
        if(stop)
        {
            break;
        }


        if(character!=nullptr){
            Tile* current_tile = character->getChar_tile();

            int dest_row = current_tile->getRow();
            int dest_col = current_tile->getCol();

            Input_gui input_terminal;

            if(character->isHuman()){
                input_terminal = gr_ui->move();
            }
            else{
                input_terminal = character->move();
            }

            if(input_terminal == up)
            {
                dest_row-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;

                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(up);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == upleft)
            {
                dest_row-=1;
                dest_col-=1;
                Tile* dest_tile =level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                   level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(left);
                    Moved = true;
                    level->updateLvlString();

                }
                continue;
            }
            if(input_terminal == upright)
            {
                dest_row-=1;
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(right);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == down)
            {
                dest_row+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                   level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(down);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == downright)
            {
                dest_row+=1;
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(right);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == downleft)
            {
                dest_row+=1;
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(left);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == right)
            {
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(right);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == left)
            {
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(left);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == terminate)
            {
                 character->setMoveDirection(terminate);
                continue;
            }
            if(input_terminal == stand)
            {
                character->setMoveDirection(character->getMoveDirection());
                Moved = true;
                level->updateLvlString();
                continue;
            }


        }
        if(dooropended){
            level->updateGraph();
            level->updateLvlString();
        }

    }
    check_alive();
    return Moved;
}

Level *DungeonCrawler::getCurrentLevel() const
{
    return level;
}
=======
    delete currentLevel;
}

bool DungeonCrawler::turn(Input input_terminal)
{
    bool Moved = false;
    for (Character* character : currentLevel->getCharacters())
    {
        if (character != nullptr){
            Tile* current_tile = character->getCurrentTile();
            int dest_row = current_tile->getRow();
            int dest_col = current_tile->getColumn();

            if (input_terminal.getVertical() == -1)
            {
                dest_row -= 1;
                Tile* dest_tile = currentLevel->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(Input(0, -1, false));
                    Moved = true;
                }
            }

            if (input_terminal.getVertical() == 1)
            {
                dest_row += 1;
                Tile* dest_tile = currentLevel->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(Input(0, 1, false));
                    Moved = true;
                }
            }

            if (input_terminal.getHorizontal() == 1)
            {
                dest_col += 1;
                Tile* dest_tile = currentLevel->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(Input(1, 0, false));
                    Moved = true;
                }
            }

            if (input_terminal.getHorizontal() == -1)
            {
                dest_col -= 1;
                Tile* dest_tile = currentLevel->getTile(dest_row, dest_col);
                if(current_tile->moveTo(dest_tile, character)){
                    character->setMoveDirection(Input(-1, 0, false));
                    Moved = true;
                }
            }

            if (input_terminal.getExit())
            {
                character->setMoveDirection(Input(0, 0, true));
                return false;
            }
        }
    }
    return Moved;
}

Level* DungeonCrawler::getLevel() const
{
    return currentLevel;
}

>>>>>>> 76af6263b5e85f412b253687016dcb23b60a002d
