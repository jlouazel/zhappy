/*
** init_world.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Tue Jul  2 10:25:55 2013 louaze_j
** Last update Tue Jul  2 10:25:56 2013 louaze_j
*/

#include	<time.h>
#include	<stdlib.h>
#include	<stdbool.h>
#include	"world.h"
#include	"square.h"
#include	"player.h"
#include	"lib_std.h"
#include	"ressources.h"
#include	"server_data_options.h"

static bool	place_ressources(t_world *world)
{
  t_square		*s;
  t_ressource		*r;
  unsigned int		nb;
  unsigned int		coor;
  static e_ressource	type = 0;

  nb = 0;
  r = NULL;
  if (type == EMPTY)
    return (true);
  while (nb != DEFAULT_QTE)
    {
      coor = POS_LIST(rand() % world->width, rand() % world->height, world->width);
      s = world->map->at(world->map, coor);
      if (!(r = create_ressource(type, s)))
	return (false);
      world->qte_rs[type]++;
      nb++;
    }
  type++;
  return (place_ressources(world));
}

static t_list	*create_world(const t_options *options)
{
  unsigned int	x;
  unsigned int	y;
  t_list	*squares;

  y = 0;
  squares = NULL;
  while (y != options->y)
    {
      x = 0;
      while (x != options->x)
	{
	  if (!squares)
	    squares = new_list(new_square(x, y));
	  else
	    squares->push_back(&squares, new_square(x, y));
	  x++;
	}
      y++;
    }
  return (squares);
}

t_world		*new_world(const t_options *options)
{
  t_world	*world;

  srand(time(NULL));
  if (!(world = xcalloc(1, sizeof(*world))))
    return (NULL);
  world->qte_rs[FOOD] = 0;
  world->qte_rs[LINEMATE] = 0;
  world->qte_rs[DERAUMERE] = 0;
  world->qte_rs[SIBUR] = 0;
  world->qte_rs[MENDIANE] = 0;
  world->qte_rs[PHIRAS] = 0;
  world->qte_rs[THYSTAME] = 0;
  world->width = options->x;
  world->height = options->y;
  if (!(world->map = create_world(options)))
    return (NULL);
  if (place_ressources(world) == false)
    return (NULL);
  return (world);
}
