//
// Graphic.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 12:27:27 2013 louaze_j
// Last update Wed Jul 10 18:25:58 2013 louaze_j
//

#include	<sys/select.h>
#include	<algorithm>
#include	<iostream>
#include	"Graphic.hh"

#define		FD_MAX(f1, f2)	((f1 < f2) ? f2 : f1)

GraphicClient::GraphicClient()
  : _port(DEFAULT_PORT),
    _host(DEFAULT_HOST),
    _ready(false),
    _teams(0),
    _world(0),
    _socket(0),
    _timeUnit(0)
{
}

GraphicClient::~GraphicClient()
{
  // FERMER LA SOCKET
  delete this->_world;
}

int	GraphicClient::getPort() const
{
  return this->_port;
}

std::string const & GraphicClient::getHost() const
{
  return this->_host;
}

World	*GraphicClient::getWorld() const
{
  return this->_world;
}

t_socket const * GraphicClient::getSocket() const
{
  return this->_socket;
}

void		GraphicClient::setPort(int port)
{
  this->_port = port;
}

void		GraphicClient::setHost(std::string const & host)
{
  this->_host = host;
}

void		GraphicClient::setWorld(World *world)
{
  this->_world = world;
}

void		GraphicClient::setSocket(t_socket const * socket)
{
  if (!this->_socket)
    this->_socket = socket;
}

std::string const	GraphicClient::readOnServer() const
{
  std::string	receiv;

  if (this->_socket && this->_socket->is_valid(this->_socket))
    {
      fd_set		rfd;
      struct timeval	timeout;
      
      timeout.tv_sec = 0;
      timeout.tv_usec = 100;

      FD_ZERO(&rfd);
      FD_SET(this->_socket->_socket, &rfd);
      if (select(this->_socket->_socket + 1, &rfd, 0, 0, &timeout) < 0)
	return "";
      if (FD_ISSET(this->_socket->_socket, &rfd))
	{
	  receiv = this->_socket->read(this->_socket);
	  return receiv;
	}
    }
  return ("NiutNiut");
}

bool		GraphicClient::writeOnServer(std::string const & send) const
{
  if (this->_socket && this->_socket->is_valid(this->_socket))
    {
      fd_set		wfd;
      struct timeval	timeout;

      timeout.tv_sec = 0;
      timeout.tv_usec = 1000;

      FD_ZERO(&wfd);
      FD_SET(this->_socket->_socket, &wfd);
      if (select(this->_socket->_socket + 1, 0, &wfd, 0, &timeout) < 0)
	return false;
      if (FD_ISSET(this->_socket->_socket, &wfd))
	this->_socket->write(this->_socket, send.c_str());
    }
  return true;
}

int		GraphicClient::getTimeUnit() const
{
  return this->_timeUnit;
}

void		GraphicClient::setTimeUnit(int time)
{
  this->_timeUnit = time;
}

std::map<int, Players *> &	GraphicClient::getPlayers()
{
  return this->_players;
}

std::list<Teams *> &		GraphicClient::getTeams()
{
  return this->_teams;
}

bool		GraphicClient::isReady() const
{
  return this->_ready;
}

void		GraphicClient::setReady(bool r)
{
  this->_ready = r;
}
