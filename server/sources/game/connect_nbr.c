/*
** connect_nbr.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Thu Jul  4 00:20:07 2013 louaze_j
** Last update Fri Jul  5 09:09:15 2013 louaze_j
*/

#include	"player.h"

#include	<stdio.h>

static
const char	*connect_nbr(t_player *player,
			     const t_server *server, void *arg)
{
  (void)arg;
  printf("connect_nbr = %d\n",
	 server->game->max_players_by_team - player->team->nb_members);
  return (NULL);
}

void		_connect_nbr(t_player *player)
{
  if (player)
    {
      player->connect_nbr = &connect_nbr;
    }
}
