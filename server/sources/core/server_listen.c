/*
** server_listen.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  1 10:09:16 2013 julien fortin
** Last update Tue Jul  2 00:06:32 2013 julien fortin
*/

#include	<stdlib.h>
#include	<sys/select.h>
#include	"server.h"

bool		server_listen_player(const t_server *serv, fd_set *wfd)
{
  t_list	*clients;

  clients = serv && serv->game && serv->game->players
    ? serv->game->players : NULL;
  while (clients)
    {
      if (clients->data && ((t_player*)clients->data)->socket)
	FD_SET(((t_player*)clients->data)->socket->_socket, wfd);
      clients = clients->next;
    }
  return (true);
}
