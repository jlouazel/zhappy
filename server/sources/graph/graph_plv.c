/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 09:51:43 2013 julien fortin
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"server.h"
#include	"lib_std.h"

const char	*_graph_plv(t_graphical *graph,
			    const t_server *server,
			    const char *data)
{
  t_list	*list;
  t_player	*player;
  char		*res;
  int		id;

  (void)graph;
  if (!server || !data || !data[0])
    return ("ko\n");
  id = atoi(data);
  player = NULL;
  list = server && server->game ? server->game->players : NULL;
  while (list)
    {
      if (list->data && (int)((t_player*)list->data)->id == id)
	player = (t_player*)list->data;
      list = list->next;
    }
  if (player)
    {
      res = xcalloc(42, sizeof(*res));
      snprintf(res, 42, "plv %d %d\n", player->id, player->level);
      return (res);
    }
  return ("ko\n");
}
