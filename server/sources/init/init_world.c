/*
** init_world.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Tue Jul  2 10:25:55 2013 louaze_j
** Last update Wed Jul  3 23:54:59 2013 louaze_j
*/

#include	<stdbool.h>
#include	<strings.h>
#include	"world.h"
#include	"square.h"
#include	"player.h"
#include	"lib_std.h"
#include	"ressources.h"
#include	"server_data_options.h"

static bool	place_ressources(t_world *world)
{
  unsigned int		x;
  unsigned int		y;
  unsigned int		nb;
  unsigned int		coor;
  t_square		*s;
  static e_ressource	type = 0;

  nb = 0;
  if (type == EMPTY)
    return (true);
  while (nb != DEFAULT_QTE)
    {
      x = rand() % world->width;
      y = rand() % world->height;
      coor = POS_LIST(x, y, world->width);
      s = world->map->at(world->map, coor);
      s->content[type]++;
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

  if (!(world = xcalloc(1, sizeof(*world))))
    return (NULL);
  bzero(world->qte_rs, sizeof(*world->qte_rs));
  world->width = options->x;
  world->height = options->y;
  if (!(world->map = create_world(options)))
    return (NULL);
  if (place_ressources(world) == false)
    return (NULL);
  return (world);
}
