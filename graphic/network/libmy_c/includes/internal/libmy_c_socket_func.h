/*
** my_socket_func.h for my_ftp in /home/fortin_j/tek2/tp/ftp
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Apr  1 16:29:13 2013 julien fortin
** Last update Sat Apr 27 21:27:06 2013 julien fortin
*/

#ifndef	__MY_SOCKET_FUNC_H__
#define	__MY_SOCKET_FUNC_H__

#include	"libmy_c_socket.h"

#define SOCKET_MAX_PENDING	1024

int		_socket_bind(const t_socket *, const t_addr *);
int		_socket_listen(const t_socket *, int);
int		_socket_connect(const t_socket *, const t_addr *);
int		_socket_init_client(t_socket *, t_addr *, const char *);

t_socket_id	_socket_init(t_socket *);
t_host		*_socket_init_host(const char *);
t_socket_client	*_socket_new_client(const struct in_addr *);

void		_socket_init_server_addr(t_addr *, int);
void		_socket_init_client_properties(t_addr *, const t_host *, int);

char		*_socket_read(const t_socket *);
int		_socket_write(const t_socket *, const char *);
int		_socket_is_valid(const t_socket *);

#endif
