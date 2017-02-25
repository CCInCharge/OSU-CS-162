/******************************************************************************
** Program name: LoserStack.hpp
** Author: Charles Chen
** Date: 02/25/2017
** Description:

******************************************************************************/

#include "ListNode.hpp"

#ifndef LOSERSTACK_HPP
#define LOSERSTACK_HPP

class LoserStack
{
protected:
    int stackSize;
    ListNode* bottom;
    ListNode* top;
public:
    LoserStack();
    ~LoserStack();
    void addCreature(Creature* newCreature);
    void printLosers();
};

#endif
