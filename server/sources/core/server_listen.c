/*
** server_listen.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  1 10:09:16 2013 julien fortin
** Last update Sun Jul 14 20:53:27 2013 louaze_j
*/

#include	<stdlib.h>
#include	<sys/select.h>
#include	"server.h"
#include	"graphical.h"
#include	"player.h"

bool		server_listen_player(const t_server *serv, fd_set *rfd,
				     int *max_fd)
{
  t_list	*clients;

  clients = serv && serv->game && serv->game->players
    ? serv->game->players : NULL;
  while (clients)
    {
      if (clients->data && ((t_player*)clients->data)->socket)
	{
	  FD_SET(((t_player*)clients->data)->socket->_socket, rfd);
	  if (*max_fd < ((t_player*)clients->data)->socket->_socket)
	    *max_fd = ((t_player*)clients->data)->socket->_socket;
	}
      clients = clients->next;
    }
  return (true);
}

bool		server_listen_graph(const t_server *serv, fd_set *rfd, int *max_fd)
{
  t_list	*list;

  list = serv && serv->game ? serv->game->graphicals : NULL;
  while (list)
    {
      if (list->data && ((t_graphical*)list->data)->socket)
	{
	  FD_SET(((t_graphical*)list->data)->socket->_socket, rfd);
	  if (*max_fd < ((t_graphical*)list->data)->socket->_socket)
	    *max_fd = ((t_graphical*)list->data)->socket->_socket;
	}
      list = list->next;
    }
  return (true);
}
