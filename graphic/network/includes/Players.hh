//
// Players.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 12:19:52 2013 louaze_j
// Last update Fri Jul 12 00:29:20 2013 louaze_j
//

#include <string>
#include "eDirections.hh"

class	Players
{
private:
  int		_x;
  int		_y;
  int		_id;
  int		_level;
  std::string	_teamName;
  eDirections	_direction;

public:
  explicit Players(int x, int y, int id, int lvl, std::string const & team, eDirections dir);
  ~Players();

  int			getX() const;
  int			getY() const;
  int			getId() const;
  int			getLvl() const;
  std::string const &	getTeamName() const;
  eDirections		getDirection() const;

  void			setX(int);
  void			setY(int);
  void			setDirection(eDirections);
};
