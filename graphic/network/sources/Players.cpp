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
    _oldx(x),
    _oldy(y),
    _id(id),
    _node(0),
    _level(lvl),
    _teamName(teamName),
    _direction(dir)
{
  switch (this->_direction)
    {
    case UP:
      this->_realDirection = M_PI;
      break;
    case DOWN:
      this->_realDirection = 0;
      break;
    case LEFT:
      this->_realDirection = 3 * M_PI / 2;
      break;
    case RIGHT:
      this->_realDirection = M_PI / 2;
      break;
    }
  this->_oldDirection = _realDirection;
}

Players::~Players()
{
  std::cout << "JE MEEEUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUURS" << std::endl;
  if (this->_node)
    {
      this->_node->getCreator()->destroySceneNode(this->_node);
    }
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

float		Players::getOldDirection() const
{
  return this->_oldDirection;
}

float		Players::getRealDirection() const
{
  return this->_realDirection;
}

int		Players::getX() const
{
  return this->_x;
}

int		Players::getY() const
{
  return this->_y;
}

float		Players::getOldX() const
{
  return this->_oldx;
}

float		Players::getOldY() const
{
  return this->_oldy;
}

Ogre::SceneNode		*Players::getNode() const
{
  return this->_node;
}

void			Players::setX(int x)
{
  this->_x = x;
}

void			Players::setY(int y)
{
  this->_y = y;
}

void			Players::setOldX(float x)
{
  this->_oldx = x;
}

void			Players::setOldY(float y)
{
  this->_oldy = y;
}

<<<<<<< HEAD
=======
void			Players::setOldDirection(float d)
{
  this->_oldDirection = d;
}

void			Players::setRealDirection(float d)
{
  this->_realDirection = d;
}

>>>>>>> 00fdc835755046f16e29ce136999183f1dfc1b73
void			Players::setDirection(eDirections dir)
{
  this->_direction = dir;
  switch (this->_direction)
    {
    case UP:
      this->_realDirection = M_PI;
      break;
    case DOWN:
      this->_realDirection = 0;
      break;
    case LEFT:
      this->_realDirection = 3 * M_PI / 2;
      break;
    case RIGHT:
      this->_realDirection = M_PI / 2;
      break;
    }
}

void			Players::setLvl(int l)
{
  this->_level = l;
}

void			Players::setLvl(int l)
{
  this->_level = l;
}

void			Players::setNode(Ogre::SceneNode *n)
{
  this->_node = n;
}
