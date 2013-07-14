/*
** pdr.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 15:07:27 2013 louaze_j
** Last update Sun Jul 14 15:31:01 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"
#include	"eressources.h"

const char	*pdr(t_player *player, e_ressource ress)
{
  char		*ret;

  if (!player)
    return ("ko\n");
  if ((ret = xcalloc(42, sizeof(*ret))))
    {
      snprintf(ret, 42, "pdr %d %d\n", player->id, ress);
      return (ret);
    }
  return ("ko\n");
}
