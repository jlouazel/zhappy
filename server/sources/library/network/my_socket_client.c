/*
** my_socket_client.c for ftp in /home/fortin_j/tek2/tp/ftp
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 20:00:23 2013 julien fortin
** Last update Wed Jun 19 15:49:01 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<arpa/inet.h>
#include	<strings.h>
#include        "lib_std.h"
#include        "lib_errs.h"
#include        "lib_socket.h"
#include        "lib_socket_func.h"

t_host          *_socket_init_host(const char *hostname)
{
  t_host        *host;

  host = NULL;
  if (hostname)
    {
      host = gethostbyname(hostname);
      if (!host)
	perror("gethostbyname");
    }
  else
    my_strerror("Error: init host, undifined ptr.\n");
  return (host);
}

void	_socket_init_client_properties(t_addr *addr, const t_host *host, int p)
{
  if (!addr || !host)
    return ;
  bzero(addr, sizeof(*addr));
  addr->sin_family = AF_INET;
  bcopy(host->h_addr, &addr->sin_addr.s_addr, host->h_length);
  addr->sin_port = htons(p);
}

int	_socket_connect(const t_socket *this, const t_addr *addr)
{
  int   result;

  if (!this || !addr)
    return (my_strerror("Error: connect, undifined ptr.\n") ? -1 : -1);
  result = connect(this->_socket, (struct sockaddr *)addr, sizeof(*addr));
  if (result)
    perror("connect");
  return (result);
}

int	_socket_init_client(t_socket *this, t_addr *addr, const char *hostname)
{
  if (!this || !addr || !hostname)
    {
      delete_socket(this);
      return (my_strerror("Error: init client, undifined ptr.\n"));
    }
  this->_server = xcalloc(1, sizeof(*this->_server));
  if (!this->_server
      || (this->_server->_host = _socket_init_host(hostname)) == NULL)
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

t_socket_client         *_socket_new_client(const struct in_addr *in)
{
  t_socket_client       *client;

  if (!in)
    return (my_strerror("Error: new client, invalid ptr.\n") ? NULL : NULL);
  client = xcalloc(1, sizeof(*client));
  if (client)
    client->_ip = _socket_get_ip(in);
  return (client);
}
