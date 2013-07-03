/*
** broadcast.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jul  3 19:00:15 2013 louaze_j
** Last update Wed Jul  3 19:00:17 2013 louaze_j
*/

#include	"player.h"

static
const char	*broadcast(t_player *player, t_world *world, void *arg)
{
  (void)player;
  (void)world;
  (void)arg;
  return (NULL);
}

void		_broadcast(t_player *player)
{
  if (player)
    {
      player->broadcast = &broadcast;
    }
}
