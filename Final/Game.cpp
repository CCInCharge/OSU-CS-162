/******************************************************************************
** Program name: Game.cpp
** Author: Charles Chen
** Date: 03/13/2017
** Description:

******************************************************************************/

#include "Game.hpp"
#include "Room.hpp"
#include "ItemRoom.hpp"
#include "Player.hpp"

Game::Game()
{
    startRoom = new ItemRoom;
    Room* tempRoom1 = startRoom;
    Room* tempRoom2 = nullptr;
    Room* tempRoom3 = nullptr;
    Room* tempRoom4 = nullptr;
    Room* roomRow1 = startRoom;
    Room* roomRow2 = nullptr;
    Room* roomRow3 = nullptr;
    Room* roomRow4 = nullptr;
    for (int i = 0; i < 4; i++)
    {
        tempRoom1->setRight(new ItemRoom);
        tempRoom1->getRight()->setLeft(tempRoom1);
        tempRoom1 = tempRoom1->getRight();
    }

    tempRoom1 = roomRow1;
    roomRow2 = new ItemRoom;
    roomRow2->setUp(roomRow1);
    roomRow1->setDown(roomRow2);
    tempRoom2 = roomRow2;
    for (int i = 0; i < 4; i++)
    {
        tempRoom2->setRight(new ItemRoom);
        tempRoom2->getRight()->setLeft(tempRoom2);
        tempRoom2->getRight()->setUp(tempRoom1->getRight());
        tempRoom1->getRight()->setDown(tempRoom2->getRight());
        tempRoom1 = tempRoom1->getRight();
        tempRoom2 = tempRoom2->getRight();
    }

    tempRoom2 = roomRow2;
    roomRow3 = new ItemRoom;
    roomRow3->setUp(roomRow2);
    roomRow2->setDown(roomRow3);
    tempRoom3 = roomRow3;
    for (int i = 0; i < 4; i++)
    {
        tempRoom3->setRight(new ItemRoom);
        tempRoom3->getRight()->setLeft(tempRoom3);
        tempRoom3->getRight()->setUp(tempRoom2->getRight());
        tempRoom2->getRight()->setDown(tempRoom3->getRight());
        tempRoom2 = tempRoom2->getRight();
        tempRoom3 = tempRoom3->getRight();
    }

    tempRoom3 = roomRow3;
    roomRow4 = new ItemRoom;
    roomRow4->setUp(roomRow3);
    roomRow3->setDown(roomRow4);
    tempRoom4 = roomRow4;
    for (int i = 0; i < 4; i++)
    {
        tempRoom4->setRight(new ItemRoom);
        tempRoom4->getRight()->setLeft(tempRoom4);
        tempRoom4->getRight()->setUp(tempRoom3->getRight());
        tempRoom3->getRight()->setDown(tempRoom4->getRight());
        tempRoom3 = tempRoom3->getRight();
        tempRoom4 = tempRoom4->getRight();
    }
}

Game::~Game()
{
    Room* tempRoom1 = roomRow1;
    Room* tempRoom2 = roomRow2;
    Room* tempRoom3 = roomRow3;
    Room* tempRoom4 = roomRow4;
    while (tempRoom1->getRight() != nullptr)
    {
        tempRoom1 = tempRoom1->getRight();
        delete tempRoom1->getLeft();
    }
    delete tempRoom1;

    while (tempRoom2->getRight() != nullptr)
    {
        tempRoom2 = tempRoom2->getRight();
        delete tempRoom2->getLeft();
    }
    delete tempRoom2;

    while (tempRoom3->getRight() != nullptr)
    {
        tempRoom3 = tempRoom3->getRight();
        delete tempRoom3->getLeft();
    }
    delete tempRoom3;

    while (tempRoom4->getRight() != nullptr)
    {
        tempRoom4 = tempRoom4->getRight();
        delete tempRoom4->getLeft();
    }
    delete tempRoom4;
}

void Game::printMap()
{}
