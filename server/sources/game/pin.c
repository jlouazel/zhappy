/*
** pin.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 15:04:35 2013 louaze_j
** Last update Sun Jul 14 11:52:41 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"
#include	"eressources.h"

const char	*pin(t_player *pl)
{
  char		*ret;
  if (!pl)
    return ("ko\n");
  if ((ret = xcalloc(60, sizeof(*ret))))
    {
      snprintf(ret, 60, "pin %d %d %d %d %d %d %d %d %d %d\n",
	       pl->id, pl->x, pl->y, pl->inventory_tab[FOOD],
	       pl->inventory_tab[LINEMATE], pl->inventory_tab[DERAUMERE],
	       pl->inventory_tab[SIBUR], pl->inventory_tab[MENDIANE],
	       pl->inventory_tab[PHIRAS], pl->inventory_tab[THYSTAME]);
	return (ret);
    }
  return ("ko\n");
}
