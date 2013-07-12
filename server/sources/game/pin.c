/*
** pin.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 15:04:35 2013 louaze_j
** Last update Fri Jul 12 15:21:29 2013 louaze_j
*/

#include	"graphical.h"
#include	"eressources.h"
#include <stdio.h>

static
const char	*pin(t_graphical *graphical, const t_server *server, void *arg)
{
  t_player	*pl;

  (void)graphical;
  (void)server;
  pl = (t_player *)arg;
  printf("pin %d %d %d %d %d %d %d %d %d %d\n", pl->id, pl->x, pl->y,
	 pl->inventory_tab[FOOD], pl->inventory_tab[LINEMATE],
	 pl->inventory_tab[DERAUMERE], pl->inventory_tab[SIBUR],
	 pl->inventory_tab[MENDIANE], pl->inventory_tab[PHIRAS],
	 pl->inventory_tab[THYSTAME]);
  return (NULL);
}

void		_pin(t_graphical *graphical)
{
  if (graphical)
    {
      graphical->pin = &pin;
    }
}
