/*
** server_accept.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Thu Jun 27 17:01:27 2013 julien fortin
<<<<<<< HEAD
** Last update Fri Jul  5 11:33:05 2013 julien fortin
=======
** Last update Fri Jul  5 10:55:22 2013 louaze_j
>>>>>>> 3a91f9e714aed69cfdca71805d621237781b7934
*/

#include	<stdio.h>
#include	<sys/select.h>
#include	"lib_std.h"
#include	"player.h"
#include	"server.h"

static bool		_server_accept_player(const t_server *serv,
					      const t_socket *client)
{
  t_list	*list;

  if (serv && serv->game && client && client->is_valid(deconst_cast(client)))
    {
      list = serv->game->players;
      if (list && list->size(list))
	list->push_back(&list, (void*)create_player(client));
      else
	((t_game*)serv->game)->players = new_list((void*)create_player(client));
      printf("NEW CLIENT!\n");
      return (true);
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
