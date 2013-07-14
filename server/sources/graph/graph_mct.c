/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 07:06:26 2013 louaze_j
*/

#include	"graphical.h"
#include	"server.h"

static
const char	*mct(t_graphical *graph, const t_server *server)
{
  unsigned int	x;
  unsigned int	y;

  y = 0;
  while (y != server->game->world->height)
    {
      x = 0;
      while (x != server->game->world->width)
	{
	  graph->notify(graph, _graph_bct(graph, server, NULL));
	  x++;
	}
      y++;
    }
  return (NULL);
}

const char	*_graph_mct(t_graphical *graph,
			    const t_server *serv,
			    const char *data)
{
  (void)data;
  if (!graph || !serv)
    return ("ko\n");
  return (mct(graph, serv));
}
