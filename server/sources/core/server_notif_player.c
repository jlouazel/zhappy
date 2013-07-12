/*
** server_notif.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  1 11:45:37 2013 julien fortin
** Last update Fri Jul 12 21:01:00 2013 julien fortin
*/

#include	"server.h"
#include	"player.h"
#include	<stdio.h>
#include	<time.h>

bool			server_will_notify_player(const t_server *serv,
						  fd_set *wfd, int *max_fd)
{
  t_list	*list;
  t_player	*player;

  list = serv && serv->game && serv->game->players
    ? serv->game->players : NULL;
  while (list)
    {
      if (list->data)
	{
	  player = (t_player*)list->data;
	  if (player->io && player->io->out && player->socket)
	    {
	      FD_SET(player->socket->_socket, wfd);
	      if (*max_fd < player->socket->_socket)
		*max_fd = player->socket->_socket;
	    }
	}
      list = list->next;
    }
  if (list)
    return (true);
  return false;
}

static void		_notify_foreach_player(t_player *player)
{
  t_list	*list;
  const char	*data;

  list = player->io ? player->io->out : NULL;
  while (list)
    {
      if (list->data)
	{
	  data = (const char*)list->data;
	  player->socket->write(player->socket, data);
	}
      list = list->next;
    }
}

bool		server_notify_player(const t_server *serv, fd_set *wfd)
{
  t_list	*list;
  t_player	*player;

  if ((list = serv && serv->game && serv->game->players ?
       serv->game->players : NULL))
    {
      while (list)
	{
	  if (list->data)
	    {
	      player = (t_player*)list->data;
	      if (player->socket && FD_ISSET(player->socket->_socket, wfd))
		{
		  _notify_foreach_player(player);
		  if (player->io->out)
		    ((t_io*)player->io)->out = delete_list(player->io->out, NULL);
		}
	    }
	  list = list->next;
	}
    }
  return (true);
}
