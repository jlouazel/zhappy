/*
** fork.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul  5 09:46:29 2013 louaze_j
** Last update Sat Jul 13 16:37:49 2013 louaze_j
*/

#include	"player.h"

const char	*_player_fork(t_player *player, const t_server *server, void *arg)
{
  t_team	*team;
  t_player	*egg;
  t_list	*pls;

  if (!player->is_allowed(player))
    return (NULL);
  team = player->team;
  pls = server->game->players;
  (void)arg;
  if (team)
    {
      egg = create_player(NULL);
      team->eggs++;
      team->members->push_back(&team->members, egg);
      pls->push_back(&pls, egg);
    }
  return ("OK\n");
}
