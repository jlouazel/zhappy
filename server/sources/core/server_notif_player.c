/*
** server_notif.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  1 11:45:37 2013 julien fortin
** Last update Tue Jul  2 14:07:21 2013 julien fortin
*/

#include	"server.h"

static void	_server_wnplayer(void *data, void *arg)
{
  t_player	*player;
  fd_set	*wfd;

  if (data && arg)
    {
      player = (t_player*)data;
      wfd = (fd_set*)arg;
      if (player->io && player->io->out && player->socket)
	FD_SET(player->socket->_socket, wfd);
    }
}

bool		server_will_notify_player(const t_server *serv,
					  fd_set *wfd)
{
  t_list	*list;

  list = serv && serv->io && serv->io->out
    ? serv->io->out : NULL;
  if (list)
    list->foreach(list, &_server_wnplayer, wfd);
  else
    return (false);
  return (true);
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
  t_list	*msg;
  t_player	*player;

  (void)arg;
  if (data)
    {
      player = (t_player*)data;
      if ((msg = player->io && player->io->out ? player->io->out : NULL))
	{
	  msg->foreach(msg, &_send_data, player);
	  ((t_io*)player->io)->out = delete_list(msg, NULL);
	}
    }
}

bool		server_notify_player(const t_server *serv)
{
  t_list	*list;

  if ((list = serv && serv->io ? serv->io->out : NULL))
    {
      list->foreach(list, &_notify_foreach_player, NULL);
      ((t_io*)serv->io)->out = delete_list(list, NULL);
    }
  return (true);
}
