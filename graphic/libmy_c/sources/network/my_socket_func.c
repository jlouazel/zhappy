/*
** my_socket_func.c for my_ftp in /home/fortin_j/tek2/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 18:47:35 2013 julien fortin
** Last update Fri Apr 12 11:49:48 2013 julien fortin
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/select.h>
#include        "libmy_c_errs.h"
#include        "libmy_c_socket.h"
#include        "libmy_c_socket_func.h"

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
      free(ptr);
    }
  return (NULL);
}

static t_timeout	*_socket_set_timeout(const t_socket *this,
					     int sec, int usec)
{
  t_socket	*s;

  if (!this)
    return (NULL);
  if (!this->_timeout)
    xcalloc(1, sizeof(*this->_timeout));
  s = (t_socket *)this;
  s->_timeout->tv_sec = sec;
  s->_timeout->tv_usec = usec;
  return (this->_timeout);
}

static void	_socket_init_func(t_socket *this)
{
  if (!this)
    return ;
  this->write = &_socket_write;
  this->read = &_socket_read;
  this->is_valid = &_socket_is_valid;
  this->set_timeout = &_socket_set_timeout;
}

t_socket_id	_socket_init(t_socket *this)
{
  struct protoent	*protocol;
  t_socket_id		sock;

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
