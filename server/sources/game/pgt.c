/*
** pgt.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 15:30:15 2013 louaze_j
** Last update Sun Jul 14 15:32:12 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"
#include	"eressources.h"

const char	*pgt(t_player *player, e_ressource ress)
{
  char		*ret;

  if (!player)
    return ("ko\n");
  if ((ret = xcalloc(42, sizeof(*ret))))
    {
      snprintf(ret, 42, "pgt %d %d\n", player->id, ress);
      return (ret);
    }
  return ("ko\n");
}