/*
** bct.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Mon Jul  8 16:23:31 2013 louaze_j
** Last update Tue Jul  9 18:14:57 2013 louaze_j
*/

#include	"square.h"
#include	"server.h"
#include	"graphical.h"
#include	"eressources.h"

#include	<stdio.h>

static
const char	*bct(t_graphical *graphical, const t_server *server,
		     void *arg1, void *arg2)
{
  int		x;
  int		y;
  t_square	*square;

  (void)graphical;
  x = *(int *)arg1;
  y = *(int *)arg2;
  square =
    server->game->world->map->at(server->game->world->map,
				 POS_LIST(x, y, server->game->world->width));
  printf("bct %d %d %d %d %d %d %d %d %d\n", x, y, square->content[FOOD],
	 square->content[LINEMATE], square->content[DERAUMERE],
	 square->content[SIBUR], square->content[MENDIANE],
	 square->content[PHIRAS], square->content[THYSTAME]);
  return (NULL);
}

void		_bct(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->bct = &bct;
    }
}
