//
//  IA.cpp
//  zappy
//
//  Created by manour_m on 24/06/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#include <vector>

#include "IA.h"

IA::IA(std::string team)
{
    this->_level = 1;
    this->_pv = 10 * FOODDELAY;
    this->_team = team;
    this->_stones = {0,0,0,0,0,0};
}

IA::~IA()
{
}

void	IA::move(eDirection dir)
{
    if (dir == LEFT)
        ;
    else if (dir == FRONT)
        ;
    else
        ;
}

void	IA::hear(std::string speech)
{
}

void	IA::say(std::string speech)
{
}

void	IA::cast()
{
}

void	IA::take()
{
}

void	IA::put()
{
}

void	IA::eject()
{
}

void	IA::fork()
{
}

void	IA::see()
{
}