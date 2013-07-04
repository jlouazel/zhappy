/*
** connect_nbr.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Thu Jul  4 00:20:07 2013 louaze_j
** Last update Thu Jul  4 00:24:27 2013 louaze_j
*/

#include	"player.h"

static
const char	*connect_nbr(t_player *player,
			     const t_server *server, void *arg)
{
  (void)player;
  (void)server;
  (void)arg;
  return (NULL);
}

void		_connect_nbr(t_player *player)
{
  if (player)
    {
      player->connect_nbr = &connect_nbr;
    }
}
