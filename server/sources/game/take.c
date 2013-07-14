/*
** take.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 18:55:06 2013 louaze_j
** Last update Sun Jul 14 18:07:39 2013 louaze_j
*/

#include	"world.h"
#include	"player.h"
#include	"graphical.h"
#include	"ressources.h"
#include	"lib_strings.h"

const char	*_player_take(t_player *player, const t_server *server, void *arg)
{
  t_square		*sq;
  e_ressource		type;

  if (!player->is_allowed(player))
    return (NULL);
  type = 0;
  sq = server->game->world->map->at(server->game->world->map,
		      POS_LIST(player->x, player->y, server->game->world->width));
  while (type != EMPTY)
    {
      if (my_strcmp((char *)arg, get_str(type)) == 0)
	{
	  if (sq->content[type] == 0)
	    return ("KO\n");
	  else
	    {
	      sq->content[type]--;
	      player->inventory_tab[type]++;
	      notify_graph(server, pgt(player, type));
	      return ("OK\n");
	    }
	}
      type++;
    }
  return ("KO\n");
}
