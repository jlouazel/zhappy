/*
** my_socket_server.c for socket in /home/fortin_j/tek2/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 20:03:57 2013 julien fortin
** Last update Wed Apr  3 22:13:59 2013 julien fortin
*/

#include	<stdlib.h>
#include	<strings.h>
#include	<stdio.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include        "libmy_c_errs.h"
#include        "libmy_c_socket.h"

static const char	*_socket_get_ip(const struct in_addr *in)
{
  char	*ip;

  ip = NULL;
  if ((ip = inet_ntoa(*in)) == NULL)
    my_strerror("Warning: cannot get client IP\n");
  return (ip);
}

t_socket_client		*_socket_new_client(const struct in_addr *in)
{
  t_socket_client	*client;

  client = xcalloc(1, sizeof(*client));
  client->_ip = _socket_get_ip(in);
  return (client);
}

void			_socket_init_server_addr(t_addr *addr, int port)
{
  bzero(addr, sizeof(*addr));
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = INADDR_ANY;
  addr->sin_port = htons(port);
}

int			_socket_bind(const t_socket *this, const t_addr *addr)
{
  int   result;

  result = bind(this->_socket, (struct sockaddr *)addr, sizeof(*addr));
  if (result < 0)
    perror("bind");
  return (!result ? 1 : 0);
}

int			_socket_listen(const t_socket *this, int n)
{
  int   result;

  result = listen(this->_socket, n);
  if (result < 0)
    perror("listen");
  return (!result ? 1 : 0);
}
