/*
** server_listen.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  1 10:09:16 2013 julien fortin
** Last update Fri Jul  5 17:54:28 2013 julien fortin
*/

#include	<stdlib.h>
#include	<sys/select.h>
#include	"server.h"
#include	"player.h"

#include	<stdio.h>

bool		server_listen_player(const t_server *serv, fd_set *rfd, int *max_fd)
{
  t_list	*clients;

  clients = serv && serv->game && serv->game->players
    ? serv->game->players : NULL;
  while (clients)
    {
      puts("_");
      if (clients->data && ((t_player*)clients->data)->socket)
	{
	  printf("playerID:%d fd=%d\t%p\n", ((t_player*)clients->data)->id, ((t_player*)clients->data)->socket->_socket, ((t_player*)clients->data));
	  FD_SET(((t_player*)clients->data)->socket->_socket, rfd);
	  if (*max_fd < ((t_player*)clients->data)->socket->_socket)
	    *max_fd = ((t_player*)clients->data)->socket->_socket;
	}
      clients = clients->next;
    }
  return (true);
}
