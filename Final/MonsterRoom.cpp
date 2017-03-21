/******************************************************************************
** Program name: MonsterRoom.cpp
** Author: Charles Chen
** Date: 03/14/2017
** Description:
Implementation of MonsterRoom class.
******************************************************************************/

#include <iostream>
#include <random>
#include <string>
#include "Room.hpp"
#include "Player.hpp"
#include "MonsterRoom.hpp"

/*
MonsterRoom()
Default constructor inherits from Room. By default, the monster will be
alive in a new MonsterRoom.
*/
MonsterRoom::MonsterRoom() : Room()
{
    monsterDead = false;
}

/*
MonsterRoom(Room* up, Room* down, Room* left, Room* right)
Non-default MonsterRoom constructor sets the location of adjacent Rooms
*/
MonsterRoom::MonsterRoom(Room* up, Room* down, Room* left,
    Room* right) : Room(up, down, left, right)
{
    monsterDead = false;
}

/*
~MonsterRoom()
Empty destructor
*/
MonsterRoom::~MonsterRoom(){}

/*
printMenu(Player* player)
printMenu will print a menu with user options.
*/
void MonsterRoom::printMenu(Player* player)
{
    // The following two options are always available
    std::cout << "There's a monster! " << std::endl;
    std::cout << "1. Try to dodge the monster - 50% chance " <<
        "of losing 50% of your health" << std::endl;
    std::cout << "2. Fight the monster with your fists - "
        << "monster will die, but you will lose 25% health" << std::endl;

    // If the player has a Shotgun, provide a prompt to use it
    if (player->hasItem("Shotgun"))
    {
        std::cout << "3. Fire your shotgun! Monster will die, "
            << "but 50% chance "
            << "that you will lose 25% health" << std::endl;
    }

    else
    {
        std::cout << "3. No Shotgun" << std::endl;
    }

    // If the player has a BFG 9000, provide a prompt to use it
    if (player->hasItem("BFG 9000"))
    {
        std::cout << "4. Fire your BFG 9000! Monster will instantly "
            << "die" << std::endl;
    }
    else
    {
        std::cout << "4. No BFG 9000" << std::endl;
    }
}

/*
doSpecial(Player* player)
doSpecial performs the special function of this room. If the monster is alive,
then the player must dodge it or attack it. If the monster is dead, this method
will simply print the fact that the monster is dead.
*/
void MonsterRoom::doSpecial(Player* player)
{
    found = true;
    // If monster is dead, do nothing and return
    if (monsterDead)
    {
        std::cout << "Monster is dead" << std::endl;
        return;
    }

    std::string userInput = "";
    bool attackDone = false;

    while (!attackDone)
    {
        printMenu(player);
        std::getline(std::cin, userInput);
        // If the user chose to dodge, there is a 50% chance of success
        if (userInput == "1")
        {
            std::cout << "Trying to dodge..." << std::endl;
            if (randNum(2) == 2)
            {
                std::cout << "Success! You've dodged the monster" << std::endl;
            }
            else
            {
                // If the user fails to dodge, lose 50 health
                std::cout << "You were hit!" << std::endl;
                player->removeHealth(50);
                std::cout << "Your health is now " << player->getHealth()
                    << std::endl;
            }
            attackDone = true;
        }
        // If the user fights the monster with fists, it will die, but the
        // player will lose 25 health
        else if (userInput == "2")
        {
            std::cout << "Fighting the monster with your fists..." << std::endl;
            player->removeHealth(25);
            std::cout << "Your health is now " << player->getHealth()
                << std::endl;
            monsterDead = true;
            attackDone = true;
        }
        else if (userInput == "3")
        {
            if (player->hasItem("Shotgun"))
            // If player has a Shotgun, 50% chance of lose 25 health
            {
                std::cout << "Attacking with shotgun..." << std::endl;
                if (randNum(2) == 2)
                {
                    std::cout << "You were hit!" << std::endl;
                    player->removeHealth(25);
                    std::cout << "Your health is now " << player->getHealth()
                        << std::endl;
                }
                else
                {
                    std::cout << "You weren't hit!" << std::endl;
                }
                std::cout << "Monster is dead" << std::endl;
                monsterDead = true;
                attackDone = true;
            }
            else
            // Disallow this input if the user doesn't have a shotgun
            {
                std::cout << "You don't have a shotgun" << std::endl;
            }
        }
        else if (userInput == "4")
        {
            // If the player has a BFG 9000, monster instantly dies
            if (player->hasItem("BFG 9000"))
            {
                std::cout << "Attacking with BFG 9000" << std::endl;
                std::cout << "Monster is dead!" << std::endl;
                monsterDead = true;
                attackDone = true;
            }
            else
            // Disallow this input if the user doesn't have a BFG 9000
            {
                std::cout << "You don't have a BFG 9000" << std::endl;
            }
        }
    }

}

/*
getType()
getType() returns MonsterDead if the monster is dead, and Monster if it is alive
*/
std::string MonsterRoom::getType()
{
    if (monsterDead)
    {
        return "MonsterDead";
    }
    else
    {
        return "Monster";
    }
}

/*
randNum(int n)
randNum takes in a number n of integers, and will return a random integer
between 1 and n, inclusive.
*/
int MonsterRoom::randNum(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,n);
    return dist(gen);
}
