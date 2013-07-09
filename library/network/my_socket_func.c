/*
** my_socket_func.c for my_ftp in /home/fortin_j/tek2/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 18:47:35 2013 julien fortin
** Last update Wed Jun 19 15:50:59 2013 julien fortin
*/

#include	<strings.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/select.h>
#include        "lib_std.h"
#include        "lib_socket.h"
#include        "lib_socket_func.h"

t_socket        *delete_socket(const t_socket *this)
{
  void	*ptr;

  if (this)
    {
      close(this->_socket);
      free(this->_timeout);
      free(this->_server);
      free(this->_client);
      ptr = (void *)this;
      bzero(ptr, sizeof(*this));
      free(ptr);
    }
  return (NULL);
}

void			_socket_init_func(t_socket *this)
{
  if (!this)
    return ;
  this->write = &_socket_write;
  this->read = &_socket_read;
  this->is_valid = &_socket_is_valid;
}

t_socket_id		_socket_init(t_socket *this)
{
  struct protoent	*protocol;
  t_socket_id		sock;

  if (!this)
    return (-1);
  protocol = getprotobyname("tcp");
  if (!protocol)
    {
      perror("getprotobyname");
      return (-1);
    }
  sock = -1;
  if ((sock = socket(AF_INET, SOCK_STREAM, protocol->p_proto)) < 0)
    perror("socket");
  if (sock > 0)
    _socket_init_func(this);
  return (sock);
}
