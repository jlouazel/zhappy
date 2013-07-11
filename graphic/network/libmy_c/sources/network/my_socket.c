/*
** my_socket.c for my_socket in /home/fortin_j/tek2/tp/ftp
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 16:13:08 2013 julien fortin
** Last update Wed Jul 10 00:00:21 2013 louaze_j
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<strings.h>
#include	<string.h>
#include	<errno.h>
#include	<fcntl.h>
#include	"libmy_c_errs.h"
#include	"libmy_c_unix.h"
#include	"libmy_c_socket.h"
#include	"libmy_c_socket_func.h"
#include	"libmy_c_strings.h"

int		_socket_write(const t_socket *this, const char *str)
{
  /* fd_set		wset; */
  int			res;

  res = 0;
  if (!this || !str)
    return (-1);
  res = write(this->_socket, str, my_strlen(str));
  if (res < 0)
    perror("write");
  return (res);
}

char		*_socket_read(const t_socket *this)
{
  char		*buffer;
  char		buf[2];
  int		res;

  if (!this)
    return (NULL);
  buffer = "";
  while (42)
    {
      bzero(buf, 2);
      res = read(this->_socket, buf, 1);
      if (res < 0)
	perror("read");
      if (res <= 0 || buf[0] == '\n')
	return (buffer);
      buffer = my_concat(buffer, buf, NULL);
    }
  return ("");
}

int		_socket_is_valid(const t_socket *this)
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
	    return (my_perror("getsockopt") ? 0 : 0);
	  if (fc)
	    return (my_strerror(my_concat(strerror(fc), ".\n", NULL)) ? 0 : 0);
	  return (1);
	}
      else
	perror("fcntl");
    }
  return (0);
}

static t_socket	*_socket_accept(const t_socket *this)
{
  t_socket	*new;
  t_addr	info;
  t_socket_id	new_sckt;
  socklen_t     len;

  new = NULL;
  len = sizeof(info);
  bzero(&info, len);
  new_sckt = accept(this ? this->_socket : -1, (struct sockaddr *)&info, &len);
  if (new_sckt < 0)
    perror("accept");
  else
    {
      new = xcalloc(1, sizeof(*new));
      new->_socket = new_sckt;
      new->_port = info.sin_port;
      new->_type = SOCK_CLIENT;
      new->_client = _socket_new_client(&info.sin_addr);
      new->write = &_socket_write;
      new->read = &_socket_read;
      new->is_valid = &_socket_is_valid;
    }
  return (new);
}

const t_socket	*new_socket(int port, const char *hostname, t_socket_type t)
{
  t_socket	*this;
  t_addr	addr;

  this = xcalloc(1, sizeof(*this));
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
