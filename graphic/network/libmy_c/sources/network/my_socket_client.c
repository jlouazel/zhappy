/*
** my_socket_client.c for ftp in /home/fortin_j/tek2/tp/ftp
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 20:00:23 2013 julien fortin
** Last update Wed Apr  3 22:13:38 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<arpa/inet.h>
#include	<strings.h>
#include        "libmy_c_errs.h"
#include        "libmy_c_socket.h"

t_host          *_socket_init_host(const char *hostname)
{
  t_host        *host;

  host = NULL;
  host = gethostbyname(hostname);
  if (!host)
    perror("gethostbyname");
  return (host);
}

void	_socket_init_client_properties(t_addr *addr, const t_host *host, int p)
{
  bzero(addr, sizeof(*addr));
  addr->sin_family = AF_INET;
  bcopy(host->h_addr, &addr->sin_addr.s_addr, host->h_length);
  addr->sin_port = htons(p);
}

int	_socket_connect(const t_socket *this, const t_addr *addr)
{
  int   result;

  result = connect(this->_socket, (struct sockaddr *)addr, sizeof(*addr));
  if (result)
    perror("connect");
  return (result);
}

int	_socket_init_client(t_socket *this, t_addr *addr, const char *hostname)
{
  if (!this || !addr || !hostname)
    return (my_strerror("t_socket: undifined ptr.\n"));
  this->_server = xcalloc(1, sizeof(*this->_server));
  if ((this->_server->_host = _socket_init_host(hostname)) == NULL)
    {
      delete_socket(this);
      return (EXIT_FAILURE);
    }
  _socket_init_client_properties(addr, this->_server->_host, this->_port);
  if (_socket_connect(this, addr) < 0)
    {
      delete_socket(this);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
