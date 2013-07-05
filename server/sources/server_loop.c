/*
<<<<<<< HEAD
** server_loop.c for zhappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jun  4 03:50:35 2013 julien fortin
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Fri Jul  5 12:02:02 2013 julien fortin
=======
** Last update Fri Jul  5 10:48:29 2013 louaze_j
>>>>>>> 3a91f9e714aed69cfdca71805d621237781b7934
=======
<<<<<<< HEAD
** Last update Wed Jul  3 15:25:30 2013 julien fortin
=======
** Last update Wed Jul  3 23:53:27 2013 louaze_j
>>>>>>> e7e9f9b10b68c4ddc90f6ce03838e38d97063e6c
>>>>>>> e9fd51fd031ad594a5df0fc512cc5bb34f78eae8
=======
** server_loop.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul  5 11:17:01 2013 louaze_j
** Last update Fri Jul  5 11:17:02 2013 louaze_j
>>>>>>> df5a296c92468a0b2a9db910edd7640163a04ab5
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
  timeout->tv_usec = 1000;
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
