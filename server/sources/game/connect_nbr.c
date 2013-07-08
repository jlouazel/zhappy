/*
** connect_nbr.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Thu Jul  4 00:20:07 2013 louaze_j
** Last update Mon Jul  8 11:08:57 2013 julien fortin
*/

#include	"server.h"

#include	<stdio.h>

const char	*_player_connect_nbr(t_player *player,
			     const t_server *server, void *arg)
{
  if (!player->is_allowed(player))
    return (NULL);
  (void)arg;
  printf("connect_nbr = %d\n",
	 server->game->max_players_by_team - player->team->nb_members);
  return (NULL);
}
