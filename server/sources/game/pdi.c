/*
** pdi.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Sun Jul 14 15:32:41 2013 louaze_j
** Last update Sun Jul 14 15:34:35 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"

const char	*pdi(t_player *player)
{
  char		*ret;

  if (!player)
    return ("ko\n");
  if ((ret = xcalloc(42, sizeof(*ret))))
    {
      snprintf(ret, 42, "pdi %d\n", player->id);
      return (ret);
    }
  return ("ko\n");
}

