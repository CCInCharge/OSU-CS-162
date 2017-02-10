/******************************************************************************
** Program name: Medusa.cpp
** Author: Charles Chen
** Date: 02/05/2017
** Description:
Implementation of Medusa class
******************************************************************************/

#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Medusa.hpp"

/*
Medusa()
Constructor sets armor, strength, and name
*/
Medusa::Medusa() : Creature()
{
    this->armor = 3;
    this->strength = 8;
    this->name = "Medusa";
}

/*
~Medusa()
Empty destructor
*/
Medusa::~Medusa(){}

/*
rollAttack()
rollAttack rolls Medusa's attack die
*/
int Medusa::rollAttack()
{
    int roll = AttackDie.rollDie() + AttackDie.rollDie();

    // If Medusa rolls a 12, activate Glare
    // Roll is set to 9999 - this will kill any other character
    if (roll == 12)
    {
        roll = 9999; // Glare
        std::cout << "Medusa used Glare!" << std::endl;
    }
    else
    {
        std::cout << "Medusa rolled " << roll << " attack points!";
        std::cout << std::endl;
    }
    return roll;
}

/*
rollDefense()
rollDefense rolls Medusa's defense die
*/
int Medusa::rollDefense()
{
    int roll = DefenseDie.rollDie();
    std::cout << "Medusa rolled " << roll << " defense points!" << std::endl;
    return roll;
}
