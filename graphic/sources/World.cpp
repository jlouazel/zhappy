//
// World.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 01:46:30 2013 louaze_j
// Last update Wed Jul 10 10:55:30 2013 louaze_j
//

#include	<algorithm>
#include	"World.hh"

World::World(int width, int height)
  : _map(0),
    _width(width),
    _height(height)
{
  int	y = 0;

  while (y != height)
    {
      int x = 0;
      while (x != width)
	{
	  this->_map.push_back(new Square(x, y));
	  x++;
	}
      y++;
    }
}

static void	delete_square(Square *square)
{
  delete square;
}

World::~World()
{
  std::for_each(this->_map.begin(), this->_map.end(), delete_square);
}

int	World::getHeight() const
{
  return this->_height;
}

int	World::getWidth() const
{
  return this->_width;
}

std::vector<Square *> const & World::getMap() const
{
  return this->_map;
}
