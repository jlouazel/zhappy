//
// Graphic.cpp for zhappy in /home/louaze_j
// 
// Made by louaze_j
// Login   <louaze_j@epitech.net>
// 
// Started on  Tue Jul  9 12:27:27 2013 louaze_j
// Last update Tue Jul  9 16:38:25 2013 louaze_j
//

#include	"Graphic.hh"

GraphicClient::GraphicClient()
  : _port(DEFAULT_PORT),
    _host(DEFAULT_HOST),
    _world(0),
    _socket(0)
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
