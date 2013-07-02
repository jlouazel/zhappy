/*
** player_droite.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jun 28 16:25:02 2013 louaze_j
** Last update Fri Jun 28 17:09:11 2013 louaze_j
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

static
const char	*droite(t_player *player)
{
  look_in_good_direction(player);
  return (NULL);
}

void		_droite(t_player *player)
{
  if (player)
    {
      player->droite = &droite;
    }
}
