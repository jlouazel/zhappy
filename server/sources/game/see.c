/*
** see.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 18:32:22 2013 louaze_j
** Last update Fri Jul 12 23:49:25 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"ressources.h"
#include	"rel_positions.h"

static void	see_player(const t_server *server, int x, int y)
{
  t_list	*tmp;

  tmp = server->game->players;
  while (tmp)
    {
      if (((t_player *)tmp->data)->x == x &&
	  ((t_player *)tmp->data)->y == y)
	printf(" player");
      tmp = tmp->next;
    }
}

const char	*_player_see(t_player *player, const t_server *server, void *arg)
{
  int		x;
  int		y;
  unsigned int	i;
  t_square	*sq;
  e_ressource	type;
  unsigned int	index;

  (void)arg;
  if (!player->is_allowed(player))
    return (NULL);
  i = 0;
  index = 0;
  while (i <= player->level)
    index += LVL_I(i++);
  i = 0;
  printf("{");
  while (i < index)
    {
      type = 0;
      x = player->x + vision[player->direction][i][0];
      y = player->y + vision[player->direction][i][1];
      /* printf("\n%d-%d\n", ABS_X(x, server->game->world->width), ABS_Y(y, server->game->world->height)); */
      see_player(server, ABS_X(x, server->game->world->width), ABS_Y(y, server->game->world->height));
      sq = server->game->world->map->at(server->game->world->map,
					POS_LIST(ABS_X(x, server->game->world->width),
						 ABS_Y(y, server->game->world->height), server->game->world->width));
      while (type != EMPTY)
	{
	  if (sq && sq->content[type] != 0)
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
