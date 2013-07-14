/*
** put.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 18:58:04 2013 louaze_j
** Last update Sun Jul 14 19:32:49 2013 louaze_j
*/

#include	"world.h"
#include	"player.h"
#include	"graphical.h"
#include	"ressources.h"
#include	"lib_strings.h"
#include	"str_ressources.h"

const char	*_player_put(t_player *player, const t_server *server, void *arg)
{
  t_square	*sq;
  e_ressource	type;

  if (!player->is_allowed(player))
    return (NULL);
  type = 0;
  sq = server->game->world->map->at(server->game->world->map,
		      POS_LIST(player->x, player->y, server->game->world->width));
  while (type != EMPTY)
    {
      if (my_strcmp((char *)arg, string_ressources[type]) == 0)
	{
	  if (player->inventory_tab[type] == 0)
	    return ("ko\n");
	  else
	    {
	      player->inventory_tab[type]--;
	      sq->content[type]++;
	      notify_graph(server, pdr(player, type));
	      return ("ok\n");
	    }
	}
      type++;
    }
  return ("ko\n");
}
