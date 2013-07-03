/*
** player_inventaire.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Tue Jul  2 18:38:05 2013 louaze_j
** Last update Wed Jul  3 06:47:57 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"ressources.h"
#include	"eressources.h"

static const char *	inventaire(t_player *player)
{
  e_ressource		type;

  type = 0;
  printf("{");
  while (type != EMPTY)
    {
      if (type != 0)
	printf(", ");
      printf("%s %d", get_str(type), player->inventory[type]);
      type++;
    }
  printf("}\n");
  return (NULL);
}

void		_inventaire(t_player *player)
{
  if (player)
    {
      player->inventaire = &inventaire;
    }
}
