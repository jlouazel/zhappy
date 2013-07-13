/*
** server_exec.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Fri Jul 12 13:32:46 2013 julien fortin
** Last update Sat Jul 13 12:45:58 2013 louaze_j
*/

#include	<stdlib.h>
#include	<time.h>
#include	"server.h"

bool		_server_treat_player_data(const t_server *serv,
					  t_player *player,
					  t_data *data)
{
  const char	*res;

  if (!serv || !serv->options || !player || !data)
    return (false);
  if (data->foo
      && data->time
      < GET_CURRENT_TIME(serv->options->time))
    {
      res = data->foo(player, serv, (void*)data->data + 1);
      if (res)
	player->notify(player, res);
      player->io->in->erase(&((t_io*)player->io)->in, data);
      return (true);
    }
  return (false);
}

void		_server_exec_each_player(void *data, void *arg)
{
  const t_server	*server;
  t_player		*player;
  t_list		*list;
  t_list		*tmp;

  if (data && arg)
    {
      server = (const t_server*)arg;
      player = (t_player*)data;
      if (player->io && (list = player->io->in))
	while (list)
	  {
	    tmp = list->next;
	    if (list->data)
	      _server_treat_player_data(server, player, list->data);
	    list = tmp;
	  }
    }
}

bool		server_exec_actions(const t_server *serv)
{
  t_list	*list;

  if (serv && serv->game && (list = serv->game->players))
    {
      list->foreach(list, &_server_exec_each_player, (void*)serv);
      return (true);
    }
  return (false);
}
