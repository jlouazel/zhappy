/*
** my_socket.h for ftp in /home/fortin_j/tek2/
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 16:07:25 2013 julien fortin
** Last update Sat Apr 27 21:24:15 2013 julien fortin
*/

#ifndef	__MY_SOCKET_H__
#define	__MY_SOCKET_H__

#include        <netdb.h>
#include        <sys/types.h>
#include        <sys/socket.h>

typedef         int             t_socket_id;
typedef struct	timeval		t_timeout;
typedef struct  hostent         t_host;
typedef struct  sockaddr_in     t_addr;

typedef enum { SOCK_CLIENT, SOCK_SERV } t_socket_type;

typedef struct	s_socket_client
{
  const char	*_ip;
} t_socket_client;

typedef struct s_socket_server
{
  const char	*_hostname;
  t_host	*_host;
} t_socket_server;

typedef struct	s_socket
{
  t_socket_type	_type;
  t_socket_id	_socket;
  int		_port;
  struct timeval	*_timeout;
  t_socket_server	*_server;
  t_socket_client	*_client;

  struct s_socket	*(*accept)(const struct s_socket *);
  char			*(*read)(const struct s_socket *);
  int			(*is_valid)(const struct s_socket *);
  int			(*write)(const struct s_socket *, const char *);
  t_timeout		*(*set_timeout)(const struct s_socket *, int, int);

} t_socket;

const t_socket	*new_socket(int, const char *, t_socket_type);
t_socket	*delete_socket(const t_socket *);

#endif
