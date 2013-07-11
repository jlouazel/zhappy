//
// Players.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 14:09:53 2013 louaze_j

//

#include	"Players.hh"

Players::Players(int x, int y, int id, int lvl, std::string const & teamName, eDirections dir)
  : _x(x),
    _y(y),
    _id(id),
    _level(lvl),
    _teamName(teamName),
    _direction(dir)
{
}

Players::~Players()
{
}

int	Players::getId() const
{
  return this->_id;
}

int	Players::getLvl() const
{
  return this->_level;
}

std::string const & Players::getTeamName() const
{
  return this->_teamName;
}

eDirections	Players::getDirection() const
{
  return this->_direction;
}

int		Players::getX() const
{
  return this->_x;
}

int		Players::getY() const
{
  return this->_y;
}

void			Players::setX(int x)
{
  this->_x = x;
}

void			Players::setY(int y)
{
  this->_y = y;
}

void			Players::setDirection(eDirections dir)
{
  this->_direction = dir;
}
