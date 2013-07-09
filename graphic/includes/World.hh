//
// World.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 01:35:31 2013 louaze_j
// Last update Tue Jul  9 01:49:15 2013 louaze_j
//

#ifndef	__WORLD_HH__
#define	__WORLD_HH__

#include <vector>
#include "Square.hh"

class	World {
private:
  std::vector<Square *>	_map;
  int			_width;
  int			_height;

public:
  World(int, int);
  ~World();
};

#endif
