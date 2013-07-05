/*
** server_loop.c for zhappy in /home/fortin_j/tek2/projects/zappy/fortin_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Tue Jun  4 03:50:35 2013 julien fortin
<<<<<<< HEAD
** Last update Fri Jul  5 10:48:29 2013 louaze_j
=======
<<<<<<< HEAD
** Last update Wed Jul  3 15:25:30 2013 julien fortin
=======
** Last update Wed Jul  3 23:53:27 2013 louaze_j
>>>>>>> e7e9f9b10b68c4ddc90f6ce03838e38d97063e6c
>>>>>>> e9fd51fd031ad594a5df0fc512cc5bb34f78eae8
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/select.h>
#include	"lib_socket.h"
#include	"lib_errs.h"
#include	"lib_std.h"
#include	"server.h"

#include	"player.h"

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
#include "str_directions.h"
#include <unistd.h>
int	server_loop(const t_server *server)
{
  static int		fail_select = 0;
  struct timeval	timeout;
  fd_set		rfd;
  fd_set		wfd;
  int			max_fd;
  t_player		*pl = create_player(NULL);
  t_player		*pl2 = create_player(NULL);
  (void)pl;
  pl->x = 5;
  pl->y = 5;
  pl2->x = 15;
  pl2->y = 5;
  printf("%d - %d\n", server->game->world->width, server->game->world->height);
  printf("1) %d - %d\n", pl->x, pl->y);
  printf("2) %d - %d\n", pl2->x, pl2->y);
  printf("%s\n", string_directions[pl->direction]);
  /* pl->deport(pl, server, pl2); */
  /* printf("1) %d - %d\n", pl->x, pl->y); */
  /* printf("2) %d - %d\n", pl2->x, pl2->y); */
  pl->broadcast(pl, server, pl2);
  pl->inventory(pl, server, NULL);
  printf("x = %d - y = %d\n", pl->x, pl->y);
  sleep(10);
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
