/*
** advance.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jul  3 17:32:06 2013 louaze_j
** Last update Wed Jul  3 23:49:02 2013 louaze_j
*/
#include	"player.h"

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

static
const char	*advance(t_player *player, const t_server *server, void *arg)
{
  (void)arg;
  modify_coors(player, server->game->world);
  return ("OK\n");
}

void		_advance(t_player *player)
{
  if (player)
    {
      player->advance = &advance;
    }
}
