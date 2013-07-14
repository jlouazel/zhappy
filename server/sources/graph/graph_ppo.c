/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 07:12:20 2013 louaze_j
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"graphical.h"
#include	"server.h"

static
const char	*ppo(const t_server *server, int id)
{
  char		*buff;
  t_list	*list;
  t_player	*pl;

  buff = NULL;
  if (!server || id < 0)
    return ("ko\n");
  list = server->game ? server->game->players : NULL;
  pl = NULL;
  while (list)
    {
      if (list->data && ((int)((t_player*)list->data)->id) == id)
	{
	  pl = (t_player*)list->data;
	  break;
	}
      list = list->next;
    }
  if (!pl)
    return ("ko\n");
  sprintf(buff, "ppo %d %d %d %d\n", pl->id, pl->x, pl->y, pl->direction);
  return (buff);
}

const char	*_graph_ppo(t_graphical *graph,
			    const t_server *server,
			    const char *data)
{
  (void)graph;
  if (!server || !data || !data[0])
    return ("ko\n");
  return (ppo(server, atoi(data)));
}
