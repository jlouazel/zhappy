//
// Parser.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 10:30:51 2013 louaze_j
// Last update Wed Jul 10 10:34:34 2013 louaze_j
//

#ifndef	__SELECTER_HH__
#define	__SELECTER_HH__

#include <OgreSceneManager.h>

class Selecter
{
private:
  Ogre::SceneNode	*_node;
  int			_x;
  int			_y;

public:
  Selecter(Ogre::SceneNode *);
  ~Selecter();

  int			getX() const;
  int			getY() const;
  Ogre::SceneNode *	getNode() const;

  void	setX(int);
  void	setY(int);
  void	setNode(Ogre::SceneNode *);
};

#endif
