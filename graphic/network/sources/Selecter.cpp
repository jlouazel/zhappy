#include "Selecter.hh"

Selecter::Selecter(Ogre::SceneNode *n)
{
  this->_node = n;
  this->_x = 0;
  this->_y = 0;
}

Selecter::~Selecter()
{
}

int			Selecter::getX() const
{
  return this->_x;
}

int			Selecter::getY() const
{
  return this->_y;
}

Ogre::SceneNode *	Selecter::getNode() const
{
  return this->_node;
}

void	Selecter::setX(int x)
{
  this->_x = x;
}

void	Selecter::setY(int y)
{
  this->_y = y;
}

void	Selecter::setNode(Ogre::SceneNode *n)
{
  this->_node = n;
}