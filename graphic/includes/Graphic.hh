//
// GraphicClient.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 01:28:12 2013 louaze_j
// Last update Wed Jul 10 14:29:41 2013 louaze_j
//

#ifndef	__GRAPHIC_CLIENT_HH__
#define	__GRAPHIC_CLIENT_HH__

#include <map>
#include <list>
#include <string>
#include "Teams.hh"
#include "World.hh"

extern "C"
{
#include "libmy_c_socket.h"
}

class	GraphicClient {
private:
  int				_port;
  std::string			_host;
  std::list<Teams *>		_teams;
  World				*_world;
  t_socket const		*_socket;
  std::map<int, Players *>	_players;
  int				_timeUnit;

  public:
  GraphicClient();
  ~GraphicClient();

  void	setPort(int);
  void	setHost(std::string const &);
  void	setWorld(World *);
  void	setSocket(t_socket const *);
  void	setTimeUnit(int);

  std::list<Teams *> &		getTeams();
  std::map<int, Players *> &	getPlayers();
  int				getPort() const;
  std::string const &		getHost() const;
  World	*			getWorld() const;
  t_socket const *		getSocket() const;
  int				getTimeUnit() const;

  std::string const	readOnServer() const;
  bool			writeOnServer(std::string const &) const;
};

#define	DEFAULT_PORT	8080
#define	DEFAULT_HOST	"127.0.0.1"

#endif
