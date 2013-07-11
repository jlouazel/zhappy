//
// Square.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 01:57:32 2013 louaze_j
// Last update Wed Jul 10 11:44:53 2013 louaze_j
//

#include	"Square.hh"
#include	"eRessources.hh"

Square::Square(int x, int y)
  : _x(x),
    _y(y)
{
  this->_content = std::vector<int>(7, 0);
}

Square::~Square()
{
}

int	Square::getX() const
{
  return this->_x;
}

int	Square::getY() const
{
  return this->_y;
}

std::vector<int> & Square::getContent()
{
  return this->_content;
}
