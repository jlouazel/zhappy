/*
** broadcast.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jul  3 19:00:15 2013 louaze_j
** Last update Wed Jul  3 23:50:23 2013 louaze_j
*/

#include	"player.h"

#include	<stdio.h>

static
const char	*broadcast(t_player *player, const t_server *server, void *arg)
{
  t_player	*player_br;

  player_br = (t_player *)arg;
  printf("%d\n", player_br->x);
  (void)player;
  (void)server;
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
