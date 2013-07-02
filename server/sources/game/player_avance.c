/*
** player_avance.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jun 28 10:44:41 2013 louaze_j
** Last update Fri Jun 28 16:39:22 2013 louaze_j
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
const char	*avance(t_player *player, t_world *world)
{
  modify_coors(player, world);
  return (NULL); /* OK */
}

void		_avance(t_player *player)
{
  if (player)
    {
      player->avance = &avance;
    }
}
