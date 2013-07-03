/*
** deport.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Thu Jul  4 00:33:07 2013 louaze_j
** Last update Thu Jul  4 00:36:11 2013 louaze_j
*/

#include	"player.h"

static
const char	*deport(t_player *player, const t_server *server, void *arg)
{
  (void)player;
  (void)server;
  (void)arg;
  return (NULL);
}

void		_deport(t_player *player)
{
  if (player)
    {
      player->deport = &deport;
    }
}
