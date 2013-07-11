//
// Teams.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Wed Jul 10 12:12:51 2013 louaze_j
// Last update Wed Jul 10 14:15:39 2013 louaze_j
//

#include	<algorithm>
#include	"Teams.hh"

Teams::Teams(std::string const & name)
  : _name(name),
    _members(0)
{
}

static
void		deleteMember(Players *player)
{
  if (player)
    delete player;
}

Teams::~Teams()
{
  std::for_each(this->_members.begin(), this->_members.end(), deleteMember);
}

std::string const &	Teams::getName() const
{
  return this->_name;
}

std::list<Players *> &	Teams::getMembers()
{
  return this->_members;
}
