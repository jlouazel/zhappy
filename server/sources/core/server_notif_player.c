/*
** server_notif_player.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 22:23:50 2013 julien fortin
** Last update Sun Jul 14 22:24:27 2013 julien fortin
*/

#include	<stdio.h>
#include	<time.h>
#include	"server.h"
#include	"player.h"
#include	"lib_std.h"
#include	"lib_strings.h"

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
  return (false);
}

static void		_notify_foreach_player(t_player *player)
{
  t_list	*list;
  char		*data;
  char		*disp;
  unsigned int	i;

  list = player->io ? player->io->out : NULL;
  while (list)
    {
      if (list->data)
	{
	  data = (char*)list->data;
	  player->socket->write(player->socket, data);
	  i = my_strlen(data);
	  if (i > 0)
	    {
	      disp = my_strndup(data, 0, i - 1);
	      if (disp)
	  	printf("%d:\tSending message \"%s\" to %u\n",
	  	       get_current_timestamp(),
	  	       disp, player->id);
	      xfree((void**)&disp, 0);
	    }
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
