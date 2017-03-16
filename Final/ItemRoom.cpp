/******************************************************************************
** Program name: ItemRoom.cpp
** Author: Charles Chen
** Date: 03/12/2017
** Description:

******************************************************************************/

#include "Room.hpp"
#include "Player.hpp"
#include "ItemRoom.hpp"
#include "inputValidator.hpp"
#include <string>
#include <set>
#include <iostream>

ItemRoom::ItemRoom() : Room(){}

ItemRoom::ItemRoom(Room* up, Room* down, Room* left,
        Room* right) : Room(up, down, left, right){}

ItemRoom::ItemRoom(std::string item, Room* up, Room* down, Room* left,
    Room* right) : Room(up, down, left, right)
{
    this->roomItems.insert(item);
}

ItemRoom::ItemRoom(std::set<std::string> roomItems) : Room()
{
    this->roomItems = roomItems;
}

ItemRoom::ItemRoom(std::set<std::string> roomItems, Room* up, Room* down,
        Room* left, Room* right) : Room(up, down, left, right)
{
    this->roomItems = roomItems;
}

ItemRoom::~ItemRoom(){}

void ItemRoom::printItems()
{
    if (roomItems.size() == 0)
    {
        std::cout << "No items in room" << std::endl;
    }
    else
    {
        std::cout << "Items in room:" << std::endl;
        std::set<std::string>::iterator item;
        for (item = roomItems.begin(); item != roomItems.end(); item++)
        {
            std::cout << *item << std::endl;
        }
    }
}

void ItemRoom::pickUpItem(std::string item, Player* player)
{
    if (roomItems.find(item) != roomItems.end())
    {
        player->addItem(item);
        roomItems.erase(item);
    }
    else
    {
        std::cout << "This room doesn't have a " << item << std::endl;
    }
}

void ItemRoom::dropItem(std::string item, Player* player)
{
    if (player->hasItem(item))
    {
        roomItems.insert(item);
    }
    player->removeItem(item);
}

void ItemRoom::printMenu()
{
    std::cout << "Select a menu option: " << std::endl;
    std::cout << "1. Show items in this room" << std::endl;
    std::cout << "2. Pick up items in this room" << std::endl;
    std::cout << "3. Drop an item in this room" << std::endl;
    std::cout << "4. Leave this room" << std::endl;
}

void ItemRoom::doSpecial(Player* player)
{
    found = true;
    int selection = -1;
    std::string userInput = "";

    while (selection != 4)
    {
        printMenu();
        std::cin >> selection;
        // cin.clear will clear the error flag in cin if an invalid input is
        // presented
        std::cin.clear();
        std::cin.ignore(100, '\n');

        // Selects submenu item
        switch (selection)
        {
            case 1:
                printItems();
            break;

            case 2:
                printItems();
                inputValidator(userInput, "What would you like to pick up?");
                pickUpItem(userInput, player);
            break;

            case 3:
                player->printItems();
                inputValidator(userInput, "What would you like to drop?");
                dropItem(userInput, player);
            break;

            case 4:
            break;

            default:
            std::cout << "Enter a valid menu item (1 through 4)";
            std::cout << std::endl;
        }
    }
}

std::string ItemRoom::getType()
{
    if (roomItems.size() == 0)
    {
        return "Empty";
    }
    else
    {
        return "Item";
    }
}
