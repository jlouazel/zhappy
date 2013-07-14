/*
** pex.c for zhappy in /home/louaze_j
** 
** Made by louaze_j
** Login   <louaze_j@epitech.net>
** 
** Started on  Fri Jul 12 17:23:21 2013 louaze_j
** Last update Sun Jul 14 13:38:14 2013 louaze_j
*/

#include	<stdio.h>
#include	"player.h"
#include	"lib_std.h"

const char	*pex(t_player *player)
{
  char		*ret;

  if (!player)
    return ("ko\n");
  if ((ret = xcalloc(15, sizeof(*ret))))
    {
      snprintf(ret, 15, "pex %d\n", player->id);
      return (ret);
    }
  return ("ko\n");
}
