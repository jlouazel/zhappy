/*
** deport.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Thu Jul  4 00:33:07 2013 louaze_j
** Last update Sun Jul 14 19:32:28 2013 louaze_j
*/

#include	<stdbool.h>
#include	"player.h"
#include	"graphical.h"

static
void		get_pointed_square_pos(t_player *player,
				       const t_server *server, int *x, int *y)
{
  if (player->direction == UP)
    *y = ABS_Y(player->y - 1, server->game->world->height);
  else if (player->direction == DOWN)
    *y = ABS_Y(player->y + 1, server->game->world->height);
  else if (player->direction == LEFT)
    *x = ABS_X(player->x - 1, server->game->world->height);
  else if (player->direction == RIGHT)
    *x = ABS_X(player->x + 1, server->game->world->height);
}

const char	*_player_deport(t_player *player, const t_server *server, void *arg)
{
  t_list	*l;
  t_player	*pl;
  bool		done;

  (void)arg;
  done = false;
  if (!player->is_allowed(player))
    return (NULL);
  l = server->game->players;
  while (l)
    {
      pl = l->data;
      if (player != pl && player->x == pl->x && player->y == pl->y)
	{
	  get_pointed_square_pos(player, server, &pl->x, &pl->y);
	  done = true;
	  notify_graph(server, pex(player));
	}
      l = l->next;
    }
  return ((done == true) ? "ok\n" : "ko\n");
}
