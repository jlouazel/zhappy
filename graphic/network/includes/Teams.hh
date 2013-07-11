//
// Teams.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 12:06:04 2013 louaze_j
// Last update Wed Jul 10 14:16:08 2013 louaze_j
//

#ifndef	__TEAMS_HH__
#define	__TEAMS_HH__

#include <list>
#include <string>
#include "Players.hh"

class	Teams
{
private:
  std::string		_name;
  std::list<Players *>	_members;

public:
  Teams(std::string const &);
  ~Teams();

  std::string const &		getName() const;
  std::list<Players *> &	getMembers();
};

#endif
