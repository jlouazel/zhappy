/*
** server_accept.c for zappy in /home/fortin_j/tek2/projects/zappy/zappy-2016-louaze_j/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Thu Jun 27 17:01:27 2013 julien fortin
** Last update Sun Jul 14 06:34:53 2013 louaze_j
*/

#include	<stdio.h>
#include	<time.h>
#include	<sys/select.h>
#include	<stdio.h>
#include	"lib_std.h"
#include	"lib_strings.h"
#include	"player.h"
#include	"graphical.h"
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
        {
	  if (client->_client)
	    printf("*** New connection from %s:%d\n",
		   client->_client->_ip, client->_port);
	  else
	    printf("*** New connection.\n");
	    _server_accept_player(server, client);
	}
    }
}

void		_server_get_new_graphic(const t_server *serv, t_player *player)
{
  const t_socket	*socket;
  t_graphical		*graph;
  unsigned int		id;

  socket = player->socket;
  player->socket = NULL;
  id = player->id;
  delete_player(player, serv);
  if (serv && serv->game && (graph = new_graphical_client(socket, id)))
    {
      if (serv->game->graphicals)
	((t_game*)serv->game)->graphicals->push_back
	  ((t_list**)&serv->game->graphicals, (void*)graph);
      else
	((t_game*)serv->game)->graphicals = new_list((void*)graph);
      //notif_queue_for_graph(graph, "bct...\);
      //notif_queue_for_graph(graph, "bct...\);
      //notif_queue_for_graph(graph, "bct...\);
      //notif_queue_for_graph(graph, "bct...\);
      _welcome(graph, serv);
    }
}

bool            server_get_auth_from_player(const t_server *serv,
                                            t_player *player,
                                            const char *data)
{
  t_list        *list;

  if (!my_strcmp("GRAPHIC", data))
    {
      _server_get_new_graphic(serv, player);
      return (true);
    }
  else if ((list = serv && serv->game ? serv->game->teams : NULL))
    while (list)
      {
        if (list->data && !my_strcmp(((t_team*)list->data)->name, data))
          return (((t_team*)list->data)->add_player(((t_team*)list->data), serv, player));
        list = list->next;
      }
  if (player && player->socket
      && player->socket->is_valid(deconst_cast(player->socket)))
    player->socket->write(player->socket, "ko\n");
  {
    printf("%d:\tSending message \"ko\" to %d\n", (int)GET_CURRENT_TIME(1), player->id);
    delete_player(player, serv);
  }
  return (false);
}
