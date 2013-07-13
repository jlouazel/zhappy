/*
** fork.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul  5 09:46:29 2013 louaze_j
<<<<<<< HEAD
** Last update Sat Jul 13 16:37:49 2013 louaze_j
=======
** Last update Sat Jul 13 17:56:11 2013 julien fortin
>>>>>>> 6b5c1317b57794fda28f3e4557c6ee6cda3549fa
*/

#include	"player.h"

const char	*_player_fork(t_player *player, const t_server *server, void *arg)
{
  t_team	*team;
  t_player	*egg;
  t_list	*pls;

  if (!player->is_allowed(player))
    return ("ko\n");
  team = player->team;
  pls = server->game->players;
  (void)arg;
  if (team)
    {
      egg = create_player(NULL);
      team->eggs++;
      team->members->push_back(&team->members, egg);
      pls->push_back(&pls, egg);
      return ("ok\n");
    }
  return ("ko\n");
}
