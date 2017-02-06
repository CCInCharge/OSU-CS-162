/******************************************************************************
** Program name: Creature.hpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:

******************************************************************************/

#include "Die.hpp"

#ifndef CREATURE_HPP
#define CREATURE_HPP

class Creature
{
public:
    Creature();
    virtual ~Creature();
    virtual int rollAttack() = 0;
    virtual int rollDefense() = 0;
    int getArmor();
    int getStrength();
    int getLife();
    virtual void takeDamage(int attack, int defense);
protected:
    int armor;
    int strength;
    int life;
    Die AttackDie;
    Die DefenseDie;
};

#endif
