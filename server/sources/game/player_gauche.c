/*
** player_gauche.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jun 28 16:49:57 2013 louaze_j
** Last update Fri Jun 28 16:50:44 2013 louaze_j
*/

#include	"player.h"

static void	look_in_good_direction(t_player *player)
{
  if (player->direction == UP)
    player->direction = LEFT;
  else if (player->direction == DOWN)
    player->direction = RIGHT;
  else if (player->direction == LEFT)
    player->direction = DOWN;
  else if (player->direction == RIGHT)
    player->direction = UP;
}

static
const char	*gauche(t_player *player)
{
  look_in_good_direction(player);
  return (NULL);
}

void		_gauche(t_player *player)
{
  if (player)
    {
      player->gauche = &gauche;
    }
}