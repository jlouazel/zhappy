/*
** see.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 18:32:22 2013 louaze_j
** Last update Sun Jul  7 15:07:49 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"ressources.h"
#include	"rel_positions.h"

static void	see_player(t_player *player, const t_server *server, int x, int y)
{
  unsigned int	i;
  t_player	*pl;

  i = 0;
  while (i != server->game->players->size(server->game->players))
    {
      pl = server->game->players->at(server->game->players, i);
      if (pl != player && pl->x == x && pl->y == y)
	printf(" player");
      i++;
    }
}

const char	*_player_see(t_player *player, const t_server *server, void *arg)
{
  unsigned int		i;
  unsigned int		index;
  e_ressource		type;
  t_square		*sq;

  i = 0;
  (void)arg;
  index = 0;
  while (i <= player->level)
    index += LVL_I(i++);
  i = 0;
  printf("{");
  while (i < index)
    {
      type = 0;
      see_player(player, server, ABS_X(vision[player->direction][i][0], server->game->world->width), ABS_Y(vision[player->direction][i][1], server->game->world->height));
      sq = server->game->world->map->at(server->game->world->map,
		       POS_LIST(ABS_X(vision[player->direction][i][0],
				      server->game->world->width),
				ABS_Y(vision[player->direction][i][1],
				      server->game->world->height), server->game->world->width));
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
