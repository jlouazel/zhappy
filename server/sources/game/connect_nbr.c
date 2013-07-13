/*
** connect_nbr.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Thu Jul  4 00:20:07 2013 louaze_j
** Last update Sat Jul 13 20:08:52 2013 louaze_j
*/

#include	<stdio.h>
#include	"server.h"
#include	"lib_strings.h"

const char	*_player_connect_nbr(t_player *player,
			     const t_server *server, void *arg)
{
  char		*ret;
  char		buff[11];

  (void)arg;
  ret = "";
  if (!player->is_allowed(player))
    return (NULL);

  sprintf(buff, "%d\n", server->game->max_players_by_team - player->team->nb_members);
  ret = my_concat(ret, buff, NULL);
  return (ret);
}

int		_player_connect_nbr_int(const t_server *server, void *arg)
{
  t_team	*team;

  team = (t_team *)arg;
  return (server->game->max_players_by_team - team->nb_members);
}
