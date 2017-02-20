/******************************************************************************
** Program name: Rock.hpp
** Author: Charles Chen
** Date: 02/19/2017
** Description:
Specification of Rock class.
******************************************************************************/

#include <string>
#include "Tool.hpp"

#ifndef ROCK_HPP
#define ROCK_HPP

class Rock : public Tool
{
public:
    Rock();
    Rock(int strength);
    virtual std::string fight(Tool* opponentTool);
};

#endif
