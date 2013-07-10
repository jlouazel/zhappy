/*
** server_accept.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Thu Jun 27 17:01:27 2013 julien fortin
** Last update Tue Jul  9 21:22:02 2013 julien fortin
*/

#include	<stdio.h>
#include	<sys/select.h>
#include	"lib_std.h"
#include	"player.h"
#include	"server.h"

static bool		_server_accept_player(const t_server *serv,
					      const t_socket *client)
{
  t_player	*player;
  t_list	*list;

  if (serv && serv->game && client && client->is_valid(deconst_cast(client)))
    {
      list = serv->game->players;
      player = create_player(client);
      if (player && list && list->size(list))
	list->push_back(&list, (void*)player);
      else if (player)
	((t_game*)serv->game)->players = new_list((void*)player);
      if (player)
	player->notify(player, "BIENVENUE\n");
      return (player ? true : false);
    }
  return (false);
}

void		server_accept(const t_server *server, const fd_set *rfd)
{
  t_socket      *client;

  if (server && server->socket && FD_ISSET(server->socket->_socket, rfd))
    {
      if ((client = server->socket->accept(server->socket)))
        _server_accept_player(server, client);
    }
}
