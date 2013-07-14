/*
** graph_msz.c for zappy in /home/fortin_j/tek2/projects/zappy/git/zhappy/server
**
** Made by julien fortin
** Login   <fortin_j@epitech.net>
**
** Started on  Sun Jul 14 00:31:59 2013 julien fortin
** Last update Sun Jul 14 06:52:59 2013 louaze_j
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"graphical.h"
#include	"lib_std.h"
#include	"server.h"
#include	"square.h"
#include	"eressources.h"

static
const char	*bct(const t_server *server,
		     int x, int y)
{
  char		*buff;
  t_square	*square;

  buff = NULL;
  square =
    server->game->world->map->at(server->game->world->map,
				 POS_LIST(x, y, server->game->world->width));
  sprintf(buff, "bct %d %d %d %d %d %d %d %d %d\n", x, y, square->content[FOOD],
	 square->content[LINEMATE], square->content[DERAUMERE],
	 square->content[SIBUR], square->content[MENDIANE],
	 square->content[PHIRAS], square->content[THYSTAME]);
  return (buff);
}

const char	*_graph_bct(t_graphical *graph,
			    const t_server *serv,
			    const char *data)
{
  char	*tok;
  int	x;
  int	y;

  if (!graph || !serv || !data || !data[0])
    return ("ko\n");
  x = -1;
  y = -1;
  tok = strtok(deconst_cast(data), " \t");
  while (tok && (x < 0 || y < 0))
    {
      if (x < 0)
	x = atoi(tok);
      else if (y < 0)
	y = atoi(tok);
      tok = strtok(NULL, " \t");
    }
  if (x >= 0 && y >= 0)
    return ((bct(serv, x, y)));
  return ("ko\n");
}
