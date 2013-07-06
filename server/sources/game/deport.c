/*
** deport.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Thu Jul  4 00:33:07 2013 louaze_j
** Last update Fri Jul  5 19:06:49 2013 julien fortin
*/

#include	"player.h"

static
void		get_pointed_square_pos(t_player *player,
				       const t_server *server, int *x, int *y)
{
  if (player->direction == UP)
    *y = ABS_Y(player->y - 1, server->game->world->height);
  else if (player->direction == DOWN)
    *y = ABS_Y(player->y + 1, server->game->world->height);
  else if (player->direction == LEFT)
    *x = ABS_X(player->x - 1, server->game->world->height);
  else if (player->direction == RIGHT)
    *x = ABS_X(player->x + 1, server->game->world->height);
}

const char	*_player_deport(t_player *player, const t_server *server, void *arg)
{
  int		x;
  int		y;
  t_player	*dest;

  dest = (t_player *)arg;
  x = dest->x;
  y = dest->y;
  if (player->x == dest->x && player->y == dest->y)
    get_pointed_square_pos(player, server, &x, &y);
  dest->x = x;
  dest->y = y;
  return (NULL);
}
