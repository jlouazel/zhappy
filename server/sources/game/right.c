/*
** right.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 18:23:05 2013 louaze_j
** Last update Mon Jul  8 11:11:43 2013 julien fortin
*/

#include	"player.h"

static void	look_in_good_direction(t_player *player)
{
  if (player->direction == UP)
    player->direction = RIGHT;
  else if (player->direction == DOWN)
    player->direction = LEFT;
  else if (player->direction == LEFT)
    player->direction = UP;
  else if (player->direction == RIGHT)
    player->direction = DOWN;
}

const char	*_player_right(t_player *player, const t_server *server, void *arg)
{
  if (!player->is_allowed(player))
    return (NULL);
  (void)server;
  (void)arg;
  look_in_good_direction(player);
  return (NULL);
}
