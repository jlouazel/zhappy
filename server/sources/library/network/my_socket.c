/*
** my_socket.c for my_socket in /home/fortin_j/tek2/tp/ftp
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 16:13:08 2013 julien fortin
** Last update Wed Jun 19 16:09:03 2013 julien fortin
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<strings.h>
#include	<string.h>
#include	<errno.h>
#include	<fcntl.h>
#include	"lib_errs.h"
#include	"lib_unix.h"
#include	"lib_std.h"
#include	"lib_socket.h"
#include	"lib_socket_func.h"
#include	"lib_strings.h"

int		_socket_write(const t_socket *this, const char *str)
{
  int			res;

  res = 0;
  if (!this || !str)
    return (-1);
  res = write(this->_socket, str, my_strlen(str));
  if (res < 0)
    perror("write");
  return (res);
}

char		*_socket_read(const t_socket *this, size_t size)
{
  char                  buffer[size];
  int                   result;

  bzero(buffer, size);
  result = read(this->_socket, buffer, size - 1);
  if (result < 0)
    {
      perror("read");
      return (NULL);
    }
  else if (!result)
    return (NULL);
  buffer[result] = 0;
  return (strdup(buffer));
}

int		_socket_is_valid(t_socket *this)
{
  socklen_t	len;
  int		fc;

  if (this && this->_socket > 0)
    {
      if (fcntl(this->_socket, F_GETFL) != -1 && errno != EBADF)
	{
	  fc = 0;
	  len = sizeof(int);
	  if ((getsockopt(this->_socket, SOL_SOCKET, SO_ERROR,
			  (void*)(&fc), &len)) < 0)
	    return ((my_perror("getsockopt") && (this->_socket = -1)) ? 0 : 0);
	  if (fc)
	    return ((my_strerror(my_concat(strerror(fc), ".\n", NULL))
		     && (this->_socket = -1)) ? 0 : 0);
	  return (1);
	}
      else
	perror("fcntl");
    }
  return (this->_socket = -1 ? 0 : 0);
}

static t_socket	*_socket_accept(const t_socket *this)
{
  t_socket	*new;
  t_addr	info;
  t_socket_id	new_sckt;
  socklen_t     len;

  if (!this)
    return (NULL);
  new = NULL;
  len = sizeof(info);
  bzero(&info, len);
  new_sckt = accept(this ? this->_socket : -1, (struct sockaddr *)&info, &len);
  if (new_sckt < 0)
    perror("accept");
  else
    {
      if (!(new = xcalloc(1, sizeof(*new))))
	return (_socket_cannot_accept(&info.sin_addr));
      new->_socket = new_sckt;
      new->_port = info.sin_port;
      new->_type = SOCK_CLIENT;
      if (!(new->_client = _socket_new_client(&info.sin_addr)))
	return (delete_socket(new));
      _socket_init_func(new);
    }
  return (new);
}

const t_socket	*new_socket(int port, const char *hostname, t_socket_type t)
{
  t_socket	*this;
  t_addr	addr;

  if (!(this = xcalloc(1, sizeof(*this))))
    return (NULL);
  if ((this->_socket = _socket_init(this)) < 0)
    return (delete_socket(this));
  this->_port = port;
  if (t == SOCK_SERV)
    {
      _socket_init_server_addr(&addr, port);
      if (!_socket_bind(this, &addr)
	  || !_socket_listen(this, SOCKET_MAX_PENDING))
	return (delete_socket(this));
      this->accept = &_socket_accept;
    }
  else if (t == SOCK_CLIENT)
    {
      if ((_socket_init_client(this, &addr, hostname)) == EXIT_FAILURE)
	return (NULL);
    }
  else
    return (delete_socket(this));
  return (this);
}
