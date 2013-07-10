/*
** server_listen.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  1 10:09:16 2013 julien fortin
** Last update Wed Jul 10 22:27:55 2013 julien fortin
*/

#include	<stdlib.h>
#include	<sys/select.h>
#include	"lib_strings.h"
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

bool		server_get_auth_from_player(const t_server *serv,
					    t_player *player,
					    const char *data)
{
  t_list	*list;

  if (!my_strcmp("GRAPHIC", data))
    {}
  else if ((list = serv && serv->game && serv->game->teams ? serv->game->teams : NULL))
    while (list)
      {
	if (list->data && !my_strcmp(((t_team*)list->data)->name, data))
	  return (((t_team*)list->data)->add_player(((t_team*)list->data), serv, player));
	list = list->next;
      }
  //acepter les mecs et voir la diff entre client ia/graphic
  return (true);
}
