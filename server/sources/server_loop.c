/*
** server_loop.c for zhappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jun  4 03:50:35 2013 julien fortin
** Last update Tue Jul  2 07:18:17 2013 louaze_j
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/select.h>
#include	"lib_socket.h"
#include	"lib_errs.h"
#include	"lib_std.h"
#include	"server.h"

static int	_init_select_serv(const t_server *server,
				  fd_set *rfd,
				  fd_set *wfd,
				  struct timeval *timeout)
{
  int		max_fd;

  FD_ZERO(rfd);
  FD_ZERO(wfd);
  max_fd = server ? server->socket->_socket : -1;
  if (server && server->socket
      && server->socket->is_valid(deconst_cast(server->socket)))
    FD_SET(server->socket->_socket, rfd);
  server_listen_player(server, rfd);
  server_will_notify_player(server, wfd);
  bzero(timeout, sizeof(*timeout));
  timeout->tv_sec = 10;
  return (max_fd);
  // FD_SET tous les users en rfd et (en wfd ceux qui ont un message dans la queue)
}

static int	_server_action(const t_server *server,
			       fd_set *rfd,
			       fd_set *wfd)
{
  (void)wfd;
  server_accept(server, rfd);
  server_notify_player(server);
  return (EXIT_SUCCESS);
}

int	server_loop(const t_server *server)
{
  static int		fail_select = 0;
  struct timeval	timeout;
  fd_set		rfd;
  fd_set		wfd;
  int			max_fd;
  t_list		*l = server->game->players;
  t_player		*pl = create_player(NULL, &l);

  pl->voir(pl, server->game->world);
  max_fd = _init_select_serv(server, &rfd, &wfd, &timeout);
  if ((select(max_fd + 1, &rfd, &wfd, NULL, &timeout)) < 0)
    {
      if (fail_select > MAX_FAIL_SELECT)
	return (my_perror("select") ? EXIT_FAILURE : EXIT_FAILURE);
      fail_select++;
    }
  else
    _server_action(server, &rfd, &wfd);
  return (EXIT_SUCCESS);
}
