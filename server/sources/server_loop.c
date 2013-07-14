/*
** server_loop.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 22:23:33 2013 julien fortin
** Last update Sun Jul 14 22:23:33 2013 julien fortin
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/select.h>
#include	<time.h>
#include	<unistd.h>
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
  server_listen_graph(server, rfd, &max_fd);
  server_will_notify_player(server, wfd, &max_fd);
  server_will_notify_graph(server, wfd, &max_fd);
  bzero(timeout, sizeof(*timeout));
  timeout->tv_usec = 5;
  return (max_fd);
}

static int	_server_action(const t_server *server,
			       fd_set *rfd,
			       fd_set *wfd)
{
  server_accept(server, rfd);
  server_players_actions(server, rfd);
  server_exec_actions(server);
  server_notify_player(server, wfd);
  server_graph_actions(server, rfd);
  server_notify_graph(server, wfd);
  server_deamon(server);
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
