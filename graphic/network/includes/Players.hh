//
// Players.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 12:19:52 2013 louaze_j
// Last update Wed Jul 10 18:28:33 2013 louaze_j
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
};
