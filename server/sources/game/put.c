/*
** put.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jul  3 18:58:04 2013 louaze_j
** Last update Wed Jul  3 18:58:53 2013 louaze_j
*/

#include	"world.h"
#include	"player.h"
#include	"ressources.h"
#include	"lib_strings.h"
#include	"str_ressources.h"

static
const char	*put(t_player *player, t_server *server, void *arg)
{
  t_square	*sq;
  e_ressource	type;

  type = 0;
  sq = server->game->world->map->at(server->game->world->map,
		      POS_LIST(player->x, player->y, server->game->world->width));
  while (type != EMPTY)
    {
      if (my_strcmp((char *)arg, string_ressources[type]) == 0)
	{
	  if (player->inventory_tab[type] == 0)
	    return ("KO\n");
	  else
	    {
	      player->inventory_tab[type]--;
	      sq->content[type]++;
	      return ("OK\n");
	    }
	}
      type++;
    }
  return ("KO\n");
}

void		_put(t_player *player)
{
  if (player)
    {
      player->put = &put;
    }
}
