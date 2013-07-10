//
// GraphicClient.hh for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 01:28:12 2013 louaze_j
// Last update Tue Jul  9 16:39:31 2013 louaze_j
//

#ifndef	__GRAPHIC_CLIENT_HH__
#define	__GRAPHIC_CLIENT_HH__

#include <string>
#include "World.hh"

extern "C"
{
#include "lib_socket.h"
}

class	GraphicClient {
private:
  int			_port;
  std::string		_host;
  World			*_world;
  t_socket const	*_socket;

  public:
  GraphicClient();
  ~GraphicClient();

  void	setPort(int);
  void	setHost(std::string const &);
  void	setWorld(World *);
  void	setSocket(t_socket const *);

  int			getPort() const;
  std::string const &	getHost() const;
  World	*		getWorld() const;
  t_socket const *	getSocket() const;
};

#define	DEFAULT_PORT	8080
#define	DEFAULT_HOST	"127.0.0.1"

#endif
