//
//  IA.h
//  zappy
//
//  Created by manour_m on 24/06/13.
//  Copyright (c) 2013 manour_m. All rights reserved.
//

#ifndef __zappy__IA__
#define __zappy__IA__

#include <string>
#include <vector>

#define FOODDELAY	126

enum eDirection {
    LEFT,
    FRONT,
    RIGHT
    };

class IA {
    unsigned int				_level;
    unsigned int				_pv;
    std::vector<unsigned int>	_stones;
    std::string					_team;
    
public:
    IA(std::string team);
    ~IA();
    
    void	move(eDirection dir);
    void	hear(std::string hear);
    void	say(std::string speech);
    void	cast();
    void	take();
    void	put();
    void	eject();
    void	fork();
    void	see();
};

#endif /* defined(__zappy__IA__) */
