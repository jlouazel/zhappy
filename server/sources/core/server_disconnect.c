/*
** server_disconnect.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  8 10:53:15 2013 julien fortin
** Last update Sat Jul 13 18:40:09 2013 julien fortin
*/

#include	<stdio.h>
#include	"lib_std.h"
#include	"server.h"
#include	"graphical.h"

bool		server_disconnect_graph(const t_server *serv,
					t_graphical *graph)
{
  if (graph)
    {
      printf("*** Graph client %d connection lost.\n", graph->id);
      printf("*** Deleting graph client %d\n", graph->id);
      graph->socket = delete_socket(graph->socket);
    }
  else
    {
      printf("*** Graph client undifined connection lost.\n");
      printf("*** Deleting graph client undifined\n");
    }
  if (serv && serv->game && serv->game->graphicals)
    serv->game->graphicals->erase((t_list**)&serv->game->graphicals, graph);
  xfree((void**)&graph, sizeof(*graph));
  return (true);
}

bool		server_disconnect_player(t_player *player)
{
  if (player)
    {
      printf("*** Player %d connection lost.\n", player->id);
      player->socket = delete_socket(player->socket);
    }
  return (true);
}

bool		server_kick_player(const t_server *serv, t_player *p)
{
  if (p)
    printf("*** Deleting player %d\n", p->id);
  else
    printf("*** Deleting undifined player.\n");
  delete_player(p, serv);
  return (true);
}
