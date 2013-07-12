//
// Players.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 12:19:52 2013 louaze_j
// Last update Fri Jul 12 00:29:20 2013 louaze_j
//

#ifndef __PLAYERS_HH__
#define __PLAYERS_HH__

#include <OgreSceneManager.h>
#include <string>
#include "eDirections.hh"

class	Players
{
private:
  int			_x;
  int			_y;
  float			_oldx;
  float			_oldy;
  int			_id;
  Ogre::SceneNode	*_node;
  int			_level;
  std::string		_teamName;
  eDirections		_direction;

public:
  explicit Players(int x, int y, int id, int lvl, std::string const & team, eDirections dir);
  ~Players();

  int			getX() const;
  int			getY() const;
  float			getOldX() const;
  float			getOldY() const;
  int			getId() const;
  int			getLvl() const;
  Ogre::SceneNode	*getNode() const;
  std::string const &	getTeamName() const;
  eDirections		getDirection() const;

  void			setX(int);
  void			setY(int);
  void			setOldX(float);
  void			setOldY(float);
  void			setLvl(int);
  void			setNode(Ogre::SceneNode *);
  void			setDirection(eDirections);
};

#endif
