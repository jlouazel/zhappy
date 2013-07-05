/*
** fork.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul  5 09:46:29 2013 louaze_j
** Last update Fri Jul  5 19:06:57 2013 julien fortin
*/

#include	"player.h"

const char	*_player_fork(t_player *player, const t_server *server, void *arg)
{
  t_team	*team;
  t_player	*egg;
  t_list	*pls;

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
