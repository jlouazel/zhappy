/*
** inventory.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Wed Jul  3 18:36:33 2013 louaze_j
** Last update Thu Jul  4 01:13:06 2013 louaze_j
*/

#define		_GNU_SOURCE

#include	<stdio.h>
#include	"player.h"
#include	"ressources.h"
#include	"eressources.h"
#include	"lib_strings.h"

#include <string.h>

static
const char *	inventory(t_player *player, const t_server *server, void *arg)
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
