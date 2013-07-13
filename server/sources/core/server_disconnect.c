/*
** server_disconnect.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Mon Jul  8 10:53:15 2013 julien fortin
** Last update Sat Jul 13 15:51:23 2013 julien fortin
*/

#include	"server.h"
#include	"graphical.h"

#include	<stdio.h>

bool		server_disconnect_graph(t_graphical *graph)
{
  if (graph)
    graph->socket = delete_socket(graph->socket);
  return (true);
}

bool		server_disconnect_player(t_player *player)
{
  if (player)
    {
      printf("Player %d disconnect.\n", player->id);
      player->socket = delete_socket(player->socket);
    }
  return (true);
}

bool		server_kick_player(const t_server *serv, t_player *p)
{
  delete_player(p, serv);
  return (true);
}
