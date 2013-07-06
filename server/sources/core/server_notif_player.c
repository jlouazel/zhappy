/*
** server_notif.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  1 11:45:37 2013 julien fortin
** Last update Fri Jul  5 18:06:19 2013 julien fortin
*/

#include	"server.h"
#include	"player.h"

bool			server_will_notify_player(const t_server *serv,
						  fd_set *wfd, int *max_fd)
{
  t_list	*list;
  t_player	*player;

  list = serv && serv->io && serv->io->out
    ? serv->io->out : NULL;
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
    }
  if (list)
    return (true);
  return false;
}

static void		_send_data(void *data, void *arg)
{
  const char	*msg;
  t_player	*player;

  if (data && arg)
    {
      msg = (const char*)data;
      player = (t_player*)arg;
      if (player->socket)
	player->socket->write(player->socket, msg);
    }
}

static void		_notify_foreach_player(void *data, void *arg)
{
  fd_set	*wfd;
  t_list	*msg;
  t_player	*player;

  if (data && arg)
    {
      wfd = (fd_set*)arg;
      player = (t_player*)data;
      if ((msg = player->io && player->io->out ? player->io->out : NULL)
	  && player->socket && FD_ISSET(player->socket->_socket, wfd))
	{
	  msg->foreach(msg, &_send_data, player);
	  ((t_io*)player->io)->out = delete_list(msg, NULL);
	}
    }
}

bool		server_notify_player(const t_server *serv, fd_set *wfd)
{
  t_list	*list;

  if ((list = serv && serv->io ? serv->io->out : NULL))
    {
      list->foreach(list, &_notify_foreach_player, wfd);
      ((t_io*)serv->io)->out = delete_list(list, NULL);
    }
  return (true);
}
