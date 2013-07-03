/*
** player_voir.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sat Jun 29 10:24:07 2013 louaze_j
** Last update Wed Jul  3 07:45:11 2013 louaze_j
*/

#include	<stdio.h>

#include	"player.h"
#include	"world.h"
#include	"ressources.h"
#include	"rel_positions.h"

#include "square.h"

#define		MY_ABS(x)	((x < 0) ? -x : x)
#define		ABS_X(x, w)	((x < 0) ? (w - MY_ABS(x)) : MY_ABS(x) % w)
#define		ABS_Y(y, h)	((y < 0) ? (h - MY_ABS(y)) : MY_ABS(y) % h)
#define		LVL_I(l)	(2 * l + 1)

static const char	*voir(t_player *player, t_world *world)
{
  unsigned int		i;
  unsigned int		index;
  e_ressource		type;
  t_square		*sq;

  i = 0;
  index = 0;
  while (i <= player->level)
    index += LVL_I(i++);
  i = 0;
  printf("{");
  while (i < index)
    {
      type = 0;
      sq =
	world->map->at(world->map,
		       POS_LIST(ABS_X(vision[player->direction][i][0],
				      world->width),
				ABS_Y(vision[player->direction][i][1],
				      world->height), world->width));
      while (type != EMPTY)
	{
	  if (sq->content[type] != 0)
	    printf(" %s", get_str(type));
	  type++;
	}
      if (i != index - 1)
	printf(",");
      i++;
    }
  printf("}\n");
  return (NULL);
}

void			_voir(t_player *player)
{
  if (player)
    {
      player->voir = &voir;
    }
}
