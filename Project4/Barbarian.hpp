/******************************************************************************
** Program name: Barbarian.hpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Specification of Barbarian class
******************************************************************************/

#include "Creature.hpp"
#include "Die.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Creature
{
public:
    Barbarian();
    Barbarian(std::string newNickname);
    Barbarian(const Barbarian &RHS);
    Barbarian& operator=(const Barbarian &RHS);
    ~Barbarian();
    virtual int rollAttack();
    virtual int rollDefense();
};

#endif
