/*
** player_voir.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sat Jun 29 10:24:07 2013 louaze_j
** Last update Tue Jul  2 10:40:06 2013 louaze_j
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

/* static void		print(void *elem, void *lal) */
/* { */
/*   (void)lal; */
/*   printf("%d\n - ", ((t_ressource *)elem)->type); */
/* } */

static const char	*voir(t_player *player, t_world *world)
{
  unsigned int		i;
  unsigned int		index;
  t_square		*sq;
  t_list		**objs;
  t_list		*tmp;
  t_ressource		*res;

  i = 0;
  index = 0;
  while (i <= player->level)
    index += LVL_I(i++);
  i = 0;
  printf("{");
  while (i < index)
    {
      sq = world->map->at(world->map, POS_LIST(ABS_X(vision[player->direction][i][0], world->width), ABS_Y(vision[player->direction][i][1], world->height), world->width));
      objs = &sq->objects;
      tmp = *objs;
      while (tmp)
	{
	  res = tmp->data;
	  printf("%s", res->get_str(res));
	  tmp = tmp->next;
	}
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
