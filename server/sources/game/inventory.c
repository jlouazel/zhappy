/*
** inventory.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jul  3 18:36:33 2013 louaze_j
** Last update Wed Jul  3 18:39:54 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"ressources.h"
#include	"eressources.h"

static
const char *	inventory(t_player *player, t_server *server, void *arg)
{
  e_ressource		type;

  (void)server;
  (void)arg;
  type = 0;
  printf("{");
  while (type != EMPTY)
    {
      if (type != 0)
	printf(", ");
      printf("%s %d", get_str(type), player->inventory_tab[type]);
      type++;
    }
  printf("}\n");
  return (NULL);
}

void		_inventory(t_player *player)
{
  if (player)
    {
      player->inventory = &inventory;
    }
}
