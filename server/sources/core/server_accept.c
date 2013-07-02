/*
** server_accept.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Thu Jun 27 17:01:27 2013 julien fortin
** Last update Tue Jul  2 00:32:27 2013 julien fortin
*/

#include	<sys/select.h>
#include	"lib_std.h"
#include	"server.h"

static bool		_server_accept_client(const t_server *serv,
					      const t_socket *client)
{
  t_list	*queue;

  if (serv && serv->game && client && client->is_valid(deconst_cast(client)))
    {
      queue = serv->game->connection_queue;
      if (queue && queue->size(queue))
	queue->push_back(&queue, (void*)client);
      else
	((t_game*)serv->game)->connection_queue = new_list((void*)client);
      return (true);
    }
  return (false);
}

void		server_accept(const t_server *server, const fd_set *rfd)
{
  t_socket      *client;

  if (FD_ISSET(server->socket->_socket, rfd))
    {
      if ((client = server->socket->accept(server->socket)))
        _server_accept_client(server, client);
    }
}
