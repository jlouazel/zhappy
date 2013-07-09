/*
** my_socket_server.c for socket in /home/fortin_j/tek2/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 20:03:57 2013 julien fortin
** Last update Wed Jun 19 15:49:17 2013 julien fortin
*/

#include	<stdlib.h>
#include	<strings.h>
#include	<stdio.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include        "lib_errs.h"
#include        "lib_std.h"
#include        "lib_socket.h"

char			*_socket_get_ip(const struct in_addr *in)
{
  char	*ip;

  ip = NULL;
  if (in)
    {
      if ((ip = inet_ntoa(*in)) == NULL)
	my_strerror("Warning: cannot get client IP address.\n");
    }
  else
    my_strerror("Warning: cannot get client IP address.\n");
  return (ip);
}

void			_socket_init_server_addr(t_addr *addr, int port)
{
  if (!addr)
    return ;
  bzero(addr, sizeof(*addr));
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = INADDR_ANY;
  addr->sin_port = htons(port);
}

int			_socket_bind(const t_socket *this, const t_addr *addr)
{
  int   result;

  if (!this || !addr)
    return (my_strerror("Error: bind, undifined ptr.\n") ? 0 : 0);
  result = bind(this->_socket, (struct sockaddr *)addr, sizeof(*addr));
  if (result < 0)
    perror("bind");
  return (!result ? 1 : 0);
}

int			_socket_listen(const t_socket *this, int n)
{
  int   result;

  if (!this)
    return (my_strerror("Error: listen, undifined ptr.\n") ? 0 : 0);
  result = listen(this->_socket, n);
  if (result < 0)
    perror("listen");
  return (!result ? 1 : 0);
}

void		*_socket_cannot_accept(const struct in_addr *addr)
{
  char	*ip;

  if (addr)
    {
      ip = _socket_get_ip(addr);
      my_strerror("Cannot accept new client");
      if (ip)
	{
	  my_strerror(" from: ");
	  my_strerror(ip);
	}
      my_strerror(": server out of memory.\n");
    }
  else
    my_strerror("Error: cannot accept new client.\n");
  return (NULL);
}
