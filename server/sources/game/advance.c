/*
** advance.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 17:32:06 2013 louaze_j
** Last update Sat Jul 13 12:32:45 2013 louaze_j
*/

#include	"player.h"
#include	<stdio.h>

static void	modify_coors(t_player *player, t_world *world)
{
  if (player->direction == LEFT)
    player->x--;
  else if (player->direction == RIGHT)
    player->x++;
  else if (player->direction == UP)
    player->y--;
  else if (player->direction == DOWN)
    player->y++;
  if (player->x < 0)
    player->x = world->width - 1;
  else if (player->x > (int)world->width - 1)
    player->x = 0;
  if (player->y < 0)
    player->y = world->height - 1;
  else if (player->y > (int)world->height - 1)
    player->y = 0;
}

#include "str_directions.h"
const char	*_player_advance(t_player *player, const t_server *server, void *arg)
{
  (void)arg;
  if (!player->is_allowed(player))
    return (NULL);
  printf("[%s] (%d;%d) -> ", string_directions[player->direction], player->x, player->y);
  modify_coors(player, server->game->world);
  printf("(%d;%d)\n", player->x, player->y);
  return ("OK\n");
}
