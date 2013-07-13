/*
** inventory.c for zhappy in /home/louaze_j
**
** Made by louaze_j
** Login   <louaze_j@epitech.net>
**
** Started on  Wed Jul  3 18:36:33 2013 louaze_j
** Last update Sat Jul 13 03:27:42 2013 louaze_j
*/

#define		_GNU_SOURCE

#include	<stdio.h>
#include	"player.h"
#include	"ressources.h"
#include	"eressources.h"
#include	"lib_strings.h"

const char *	_player_inventory(t_player *player, const t_server *server, void *arg)
{
  char			*ret;
  char			buff[11];
  e_ressource		type;

  ret = "";
  if (!player->is_allowed(player))
    return (NULL);
  (void)server;
  (void)arg;
  type = 0;
  ret = my_concat("{", NULL);
  while (type != EMPTY)
    {
      if (type != 0)
	ret = my_concat(ret, ", ", NULL);
      sprintf(buff, "%d", player->inventory_tab[type]);
      ret = my_concat(ret, get_str(type), " ", buff, NULL);
      type++;
    }
  ret = my_concat(ret, "}\n", NULL);
  return (ret);
}
