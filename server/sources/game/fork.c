/*
** fork.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Fri Jul  5 09:46:29 2013 louaze_j
** Last update Sun Jul 14 05:18:48 2013 louaze_j
*/

#include	"egg.h"
#include	"player.h"

const char	*_player_fork(t_player *player, const t_server *server, void *arg)
{
  t_team	*team;

  (void)arg;
  (void)server;
  if (!player->is_allowed(player))
    return ("ko\n");
  team = player->team;
  if (team)
    {
      if (team->eggs == NULL)
	team->eggs = new_list(new_egg(player->x, player->y));
      else
	team->eggs->push_back(&team->eggs, new_egg(player->x, player->y));
      return ("ok\n");
    }
  return ("ko\n");
}
