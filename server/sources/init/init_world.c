/*
** init_world.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Tue Jul  2 10:25:55 2013 louaze_j
** Last update Fri Jul  5 15:57:36 2013 louaze_j
*/

#include	<stdio.h>

#include	<stdbool.h>
#include	<strings.h>
#include	"log.h"
#include	"world.h"
#include	"square.h"
#include	"player.h"
#include	"lib_std.h"
#include	"ressources.h"
#include	"server_data_options.h"

static void	log_map(double cnt, double tot)
{
  int		i;
  int		percent;
  static bool	done = false;

  if (done == false)
    {
      printf("\033[%d;%dH", 3, 0);
      printf("Building map: [");
      printf("\033[%d;%dH", 3, 116);
      printf("]\n");
      done = true;
    }
  i = 0;
  percent = ((cnt / tot) * 100);
  while (i != percent)
    {
      printf("\033[%d;%dH", 3, i + 16);
      printf("#");
      i++;
    }
  printf("\033[%d;%dH", 3, 118);
  printf("%d%%\n", percent);
}

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

  x = 0;
  y = 0;
  squares = NULL;
  server_login();
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
	  log_map(x + y * options->x, options->x * options->y);
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
