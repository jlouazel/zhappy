/*
** server_loop.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Sun Jul  7 15:42:45 2013 louaze_j
** Last update Mon Jul  8 10:39:30 2013 julien fortin
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
  server_listen_player(server, rfd, &max_fd);
  server_will_notify_player(server, wfd, &max_fd);
  bzero(timeout, sizeof(*timeout));
  timeout->tv_sec = 1;
  return (max_fd);
}

static int	_server_action(const t_server *server,
			       fd_set *rfd,
			       fd_set *wfd)
{
  server_accept(server, rfd);
  server_players_actions(server, rfd);
  server_notify_player(server, wfd);
  return (EXIT_SUCCESS);
}

int	server_loop(const t_server *server)
{
  static int		fail_select = 0;
  struct timeval	timeout;
  fd_set		rfd;
  fd_set		wfd;
  int			max_fd;

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
