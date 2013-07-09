//
// main.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 01:20:33 2013 louaze_j
// Last update Tue Jul  9 02:07:18 2013 louaze_j
//

#include "World.hh"

int	main()
{
  World	*world = new World(10, 10);

  delete world;
  return 0;
}
