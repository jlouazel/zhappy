/*
** player_prend.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jul  3 06:49:36 2013 louaze_j
** Last update Wed Jul  3 07:15:20 2013 louaze_j
*/

#include	"world.h"
#include	"player.h"
#include	"ressources.h"
#include	"lib_strings.h"
#include	"str_ressources.h"

static const char	*prend(t_player *player,
			       t_world *world, void *ressource)
{
  t_square		*sq;
  e_ressource		type;

  type = 0;
  sq = world->map->at(world->map,
		      POS_LIST(player->x, player->y, world->width));
  while (type != EMPTY)
    {
      if (my_strcmp((char *)ressource, string_ressources[type]) == 0)
	{
	  if (sq->content[type] == 0)
	    return ("KO\n");
	  else
	    {
	      sq->content[type]--;
	      player->inventory[type]++;
	    return ("OK\n");
	    }
	}
      type++;
    }
  return ("KO\n");
}

void			_prend(t_player *player)
{
  if (player)
    {
      player->prend = &prend;
    }
}


